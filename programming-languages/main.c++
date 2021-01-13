#include <iostream>
#include <string>
#include <fstream> 
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


void print(const std::string str) {
    std::cout << str << std::endl;
}

void printRaw(const std::string str) {
    std::cout << std::quoted(str) << std::endl;
}

std::vector<std::string> split(const std::string str, const char delimiter = ' ') {
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> tokens;
    while (std::getline(ss, token, delimiter))
        if (!token.empty() && !std::all_of(token.begin(), token.end(), isspace))
            tokens.push_back(token);
    return tokens;
}

std::vector<std::string> readIntoLines(const std::string filename) {
    std::ifstream stream(filename);
    if (!stream.is_open()) throw std::runtime_error("Couldn't open the input file.");
    std::stringstream buffer;
    buffer << stream.rdbuf();
    return split(buffer.str(), '\n');
}

inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
{
    return ltrim(rtrim(s, t), t);
}

void parse(const std::string filename, const std::string format, const char formatDelimiter = '|') {
    std::vector<std::string> fileLines = readIntoLines(filename);

    for (std::string formatLine : split(format, '\n')) {
        // printRaw(formatLine);
        for (std::string untrimmedInstruction : split(formatLine, formatDelimiter)) {
            std::string instruction = trim(untrimmedInstruction);
            printRaw(instruction);
        }
        print("");
    }
}


int main() {
    std::string format =
    "names:height,width          |type:int |lines:0\n"
    "names:maze                  |type:char|lines:1-4|dimensions:2\n"
    "names:exitRow,exitColumn    |type:int |lines:5\n"
    "names:playerRow,playerColumn|type:int |lines:6\n"
    "names:moves                 |type:char|lines:7";

    parse("../test-input.txt", format);

    return 0;
}