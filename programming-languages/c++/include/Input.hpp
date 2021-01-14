#ifndef INPUT_HPP
#define INPUT_HPP


#include <algorithm>
#include <fstream> 
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>


#define WHITESPACE " \t\n\r\f\v"


class Input {
    public:
        void parse(const std::string filename, const std::string format, const char formatDelimiter = '|');

        int getInt(const std::string name);
        double getDouble(const std::string name);
        std::string getString(const std::string name);
        bool getBool(const std::string name);
        char getChar(const std::string name);

        std::map<std::string, int> ints;
        std::map<std::string, double> doubles;
        std::map<std::string, std::string> strings;
        std::map<std::string, bool> bools;
        std::map<std::string, char> chars;
    private:
        std::map<std::string, std::string> getInstruction(const std::string formatLine, const char formatDelimiter);
        std::vector<std::string> split(const std::string str, const char delimiter = ' ');
        std::vector<std::string> readIntoLines(const std::string filename);
        std::string& trim(std::string& s, const std::string t = WHITESPACE);
        std::string& ltrim(std::string& s, const std::string t = WHITESPACE);
        std::string& rtrim(std::string& s, const std::string t = WHITESPACE);
        void insert(const std::string name, const std::string value, const std::string type);
        void throwInvalidName(const std::string name, const std::string mapType);
};


#endif