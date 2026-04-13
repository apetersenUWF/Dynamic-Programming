#ifndef LCS_HPP
#define LCS_HPP
#include <vector>
#include <string>
class LCS{
    std::vector<std::vector<int>> arr;
    std::string lcsStr;
    public:
    LCS();
    std::string& findlcs(std::string& x, std::string& y);
    char compare(std::string& x, std::string& y);
};
#endif