#ifndef MENU_HPP
#define MENU_HPP
#include "lcs.hpp"
#include <fstream>
const std::string FILENAME1 = "twoStrings.txt";
const std::string FILENAME2 = "multiStrings.txt";
class Menu {
    void printLCSStr(const std::string& filename = FILENAME1);
    void printCompareTable(const std::string& filename = FILENAME2);
    public:
    Menu();


};
#endif