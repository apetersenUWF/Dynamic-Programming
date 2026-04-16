#ifndef MENU_HPP
#define MENU_HPP
#include "lcs.hpp"
const std::string FILENAME1 = "twoStrings.txt";
const std::string FILENAME2 = "multiStrings.txt";
class Menu {
    LCS* solver;
    void printLCSStr(const std::string& filename = FILENAME1);
    void printCompareTable(const std::string& filename = FILENAME2);
    std::string fileLookup(const int i, const std::string& filename = FILENAME2);
    public:
    Menu();
    ~Menu();
    void run();
};
#endif