#include "tools.hpp"


void print(const int n) {
    std::cout << n << std::endl;
}

void print(const double n) {
    std::cout << n << std::endl;
}

void print(const std::string str) {
    std::cout << str << std::endl;
}

void print(const char c) {
    std::cout << c << std::endl;
}


std::string& ltrim(std::string& s, const std::string t) {
    s.erase(0, s.find_first_not_of(t));
    return s;
}

std::string& rtrim(std::string& s, const std::string t) {
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

std::string& trim(std::string& s, const std::string t) {
    return ltrim(rtrim(s, t), t);
}


std::vector<std::string> split(const std::string str, const char delimiter) {
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> tokens;
    while (std::getline(ss, token, delimiter))
        if (!token.empty() && !std::all_of(token.begin(), token.end(), isspace))
            tokens.push_back(token);
    return tokens;
}


void err(const std::string msg) {
    print("an error occurred: " + msg);
    exit(EXIT_FAILURE); // TODO: May need to use EXIT_SUCCESS for CodeGrade.
}