#ifndef LCS_HPP
#define LCS_HPP
#include <vector>
#include <string>
class LCS{
    std::vector<std::vector<int>> arr;
    std::string lcsStr;
    float lengthRatio(std::string& x, std::string& y);
    public:
    LCS();
    std::string& findlcs(std::string& x, std::string& y);
    int findlcslen(std::string& x, std::string& y);
    char compare(std::string& x, std::string& y);
};
#endif