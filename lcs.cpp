#include "lcs.hpp"
#include "stack.hpp"
LCS::LCS() {}

std::string& LCS::findlcs(std::string& x, std::string& y) {
    lcsStr = ""; //reset the lcs
    int xLen, yLen;
    xLen = x.size();
    yLen = y.size();
    std::vector<std::vector<int>> arr(xLen+1, std::vector<int>(yLen+1, 0));
    for (int i = 0; i < xLen+1; i++) { //column 1 all zeroes
        arr[i][0] = 0;
    }
    for (int i = 1; i < yLen+1; i++) { //column 2 all zeroes
        arr[0][i] = 0;
    }
    for (int i = 1; i < xLen+1; i++) {
        for (int j = 1; j < yLen+1; j++) {
            if (x[i-1] == y[j-1]) { //matching letters found
                arr[i][j] = arr[i-1][j-1] + 1;
            }
            else {//leters dont match
                if (arr[i-1][j] >= arr[i][j-1]) {//if the cell above is >= the cell to the left
                    arr[i][j] = arr[i-1][j];//copy the higher value to this cell
                }
                else {//the cell to the left is greater than the cell above
                    arr[i][j] = arr[i][j-1];//copy the higher value to this cell
                }
            }
        }
    }
    //array is now formed
    int i = xLen;
    int j = yLen;
    Stack<char>* lcs = new Stack<char>;
    while (i > 0 && j > 0) {
        if (x[i-1] == y[j-1]) {
            lcs->push(x[i-1]);
            i--;
            j--;
        }
    else if(arr[i-1][j] >= arr[i][j-1])
        i--;
    else 
        j--;
    }
    while (!lcs->empty()) {
        lcsStr.push_back(lcs->peek());
        lcs->pop();
    }
    delete lcs;
    return lcsStr;
}

float LCS::lengthRatio(std::string& x, std::string& y) {
    float lengthRatio = static_cast<float>(x.size()) / y.size();
    return lengthRatio;
}

int LCS::findlcslen(std::string& x, std::string& y) {
    if (x.size() == 0 || y.size() == 0) return 0;
    int maxLength = 0;
    int rows = x.size() + 1;
    int cols = y.size() + 1;
    int* upper = new int[cols];
    int* curr = new int[cols];
    for (int i = 0; i < cols; i++) upper[i] = 0; //first row is zero
    for (int i = 0; i < rows - 1; i++) {
        curr[0] = 0;
        char xChar = x[i];
        for (long unsigned int j = 0; j < y.size(); j++) {
            if (y[j] == xChar) {//match found
                int length;
                length = curr[j + 1] = upper[j] + 1;
                if (length > maxLength) maxLength = length;
            }
            else {//letters dont match
                if (upper[j+1] >= curr[j]){//cell above is greater than the one to the left
                    curr[j+1] = upper[j+1]; //copy its value
                }
                else {//cell to the left must be greater
                    curr[j+1] = curr[j]; //copy that value
                }
            }
        }
        std::swap(upper, curr);//upper is now the curr row, curr will be overwritten on the next loop
    }
    delete [] upper;
    delete [] curr;
    return maxLength;
}

char LCS::compare(std::string& x, std::string& y) {
    char identifier = '$';
    float sizeRatio = lengthRatio(x, y);
    if (sizeRatio < 0.6 || sizeRatio > 1.4) {return 'D';} //not within 40% of each other, strings are dissimilar
    int lcslength = findlcslen(x, y);
    int shortestStrLength;
    if (x.size() >= y.size()) shortestStrLength = y.size();
    else shortestStrLength = x.size();
    float lcsRatio = static_cast<float>(lcslength)/shortestStrLength;
    if (lcsRatio >= 0.5) {identifier = 'L';}
    if (lcsRatio >= 0.8) {identifier = 'M';}
    if (lcsRatio >= 0.9) {identifier = 'H';}
    return identifier;
}

