#ifndef INPUT_HPP
#define INPUT_HPP


#include <fstream> 
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "tools.hpp"


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
        std::vector<std::string> readIntoLines(const std::string filename);
        void insert(const std::string name, const std::string value, const std::string type);
        void throwInvalidName(const std::string name, const std::string mapType);
        std::vector<std::string> getValues(const int varNamesCount, const std::vector<std::string>& fileLines, int& curLine, const bool multiline);
        int getLineCountMultilineString(const int startLine, const int maxLine, const std::vector<std::string>& fileLines);
        bool isDigits(const std::string& str);
};


#endif