#ifndef TOOLS_HPP
#define TOOLS_HPP


#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>


#define WHITESPACE " \t\n\r\f\v"


void print(const int n);
void print(const double n);
void print(const std::string str);
void print(const char c);

std::string& trim(std::string& s, const std::string t = WHITESPACE);
std::string& ltrim(std::string& s, const std::string t = WHITESPACE);
std::string& rtrim(std::string& s, const std::string t = WHITESPACE);

std::vector<std::string> split(const std::string str, const char delimiter = ' ');


#endif