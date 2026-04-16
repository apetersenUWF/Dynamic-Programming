#include "menu.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

Menu::Menu() {solver = new LCS();}
Menu::~Menu() {delete solver;}

void Menu::printLCSStr(const std::string& filename) {
    std::ifstream inFS;
    inFS.open(filename);
    if (!inFS.is_open()) return;
    std::string a, b, lcs;
    getline(inFS, a);
    getline(inFS, b);
    inFS.close();
    lcs = solver->findlcs(a, b);
    std::cout << std::setw(50) << std::setfill('-') << "-" << std::endl;
    std::cout << "Original Strings:" << std::endl;
    std::cout << "1: " << a << std::endl;
    std::cout << "2: " << b << std::endl;
    std::cout << "Longest Common Subsequence:" << std::endl;
    std::cout << "Length = " << lcs.size() << std::endl;
    std::cout << lcs << std::endl;
    std::cout << std::setw(50) << std::setfill('-') << "-" << std::endl;
}

void Menu::printCompareTable(const std::string& filename) {
    std::ifstream inFS;
    inFS.open(filename);
    if (!inFS.is_open()) return;
    std::string line;
    int numStrings;
    getline(inFS, line);
    numStrings = stoi(line);
    printf("   ");
    for (int i = 0; i < numStrings; i++) {
        printf("%02d ", i);
    }
    printf("\n");
    for (int i = 0; i < numStrings; i++) {
        printf("%02d ", i);
        std::string a = fileLookup(i);
        for (int j = 0; j < numStrings; j++) {
            if (i >= j) printf(" - ");
            else {
                std::string b = fileLookup(j);
                char identifier = solver->compare(a, b);
                printf("%2c ", identifier);
            }
        }
        printf("\n");
    }
}


std::string Menu::fileLookup(const int i, const std::string& filename) {
    std::ifstream inFS;
    inFS.open(filename);
    if (!inFS.is_open()) return "";
    std::string line;
    getline(inFS, line);
    int rows = stoi(line);
    if (i > rows-1) return ""; //invalid index
    for (int j = 0; j <= i; j++) {getline(inFS, line);}
    inFS.close();
    return line;
}


void Menu::run() {
    printLCSStr();
    printCompareTable();
}