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

char LCS::compare(std::string& x, std::string& y) {
    return 'x';
}