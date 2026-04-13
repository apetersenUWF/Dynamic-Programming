#include "lcs.hpp"
#include <iostream>
#include <fstream>
int main() {
    LCS solver;
    std::string a, b;
    std::ifstream inFS;
    inFS.open("twoStrings.txt");
    getline(inFS, a);
    getline(inFS, b);
    inFS.close();
    std::string lcs = solver.findlcs(a, b);
    std::cout << "Longest Common Subsequence: " << lcs << std::endl;
    std::cout << "Length = " << lcs.size();
    return 0;
}