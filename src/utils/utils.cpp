#include "package.hpp"
#include "utils.hpp"

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(s);
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}