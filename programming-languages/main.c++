#include <iostream>
#include <string>
#include <fstream> 
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>


#define WHITESPACE " \t\n\r\f\v"


class Input {
    public:
        void parse(const std::string filename, const std::string format, const char formatDelimiter);

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
};


void print(const std::string str) {
    std::cout << str << std::endl;
}

void printRaw(const std::string str) {
    std::cout << std::quoted(str) << std::endl;
}


void Input::parse(const std::string filename, const std::string format, const char formatDelimiter = '|') {
    std::vector<std::string> fileLines = readIntoLines(filename);
    for (std::string formatLine : split(format, '\n')) {
        std::map<std::string, std::string> instruction = getInstruction(formatLine, formatDelimiter);
        // print("names: " + instruction.at("names") +  ", type: " + instruction.at("type") + ", lines: " + instruction.at("lines"));

        int lineNum = std::stoi(instruction.at("lines")); // TODO: Support line range.
        std::vector<std::string> names = split(instruction.at("names"), ',');
        std::vector<std::string> values = split(fileLines.at(lineNum));
        for (int i = 0; i < names.size(); i++)
            insert(names.at(i), values.at(i), instruction.at("type"));
    }
}

void Input::insert(const std::string name, const std::string value, const std::string type) {
    if (type == "int" || name == "bool") ints[name] = std::stoi(value);
    else if (type == "double") doubles[name] = std::stod(value);
    else if (type == "string") strings[name] = value;
    else if (type == "char") chars[name] = value[0];
}

std::map<std::string, std::string> Input::getInstruction(const std::string formatLine, const char formatDelimiter) {
    std::map<std::string, std::string> instruction;

    bool foundName = false;
    bool foundType = false;
    bool foundLine = false;
    
    for (std::string untrimmedInstruction : split(formatLine, formatDelimiter)) {
        std::string token = trim(untrimmedInstruction);
        std::vector<std::string> tokenParts = split(token, ':');

        if (tokenParts.size() != 2) throw std::runtime_error("Format instruction key didn't have a (correct) value.");

        std::string key = trim(tokenParts.at(0));
        std::string value = trim(tokenParts.at(1));

        if (key == "names") foundName = true;
        if (key == "type") foundType = true;
        if (key == "lines") foundLine = true;

        instruction[key] = value;
    }
    
    bool validInstruction = foundName && foundType && foundLine;
    if (!validInstruction) throw std::runtime_error("Format instruction keys are missing/wrong.");
    return instruction;
}

std::vector<std::string> Input::split(const std::string str, const char delimiter) {
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> tokens;
    while (std::getline(ss, token, delimiter))
        if (!token.empty() && !std::all_of(token.begin(), token.end(), isspace))
            tokens.push_back(token);
    return tokens;
}

std::vector<std::string> Input::readIntoLines(const std::string filename) {
    std::ifstream stream(filename);
    if (!stream.is_open()) throw std::runtime_error("Couldn't open the input file.");
    std::stringstream buffer;
    buffer << stream.rdbuf();
    return split(buffer.str(), '\n');
}

std::string& Input::ltrim(std::string& s, const std::string t) {
    s.erase(0, s.find_first_not_of(t));
    return s;
}

std::string& Input::rtrim(std::string& s, const std::string t) {
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

std::string& Input::trim(std::string& s, const std::string t) {
    return ltrim(rtrim(s, t), t);
}


int main() {
    Input input;

    std::string format =
    "names:height,width          |type:int |lines:0\n"
    // "names:maze                  |type:char|lines:1-4\n"
    "names:exitRow,exitColumn    |type:int |lines:5\n"
    "names:playerRow,playerColumn|type:int |lines:6\n"
    "   names  :  moves                 |   type   :   string   |    lines   :  7  \n"
    "names:temp|type:char|lines:7";

    input.parse("../test-input.txt", format);

    print(std::to_string(input.ints.at("height")));
    print(std::to_string(input.ints.at("width")));
    print(std::to_string(input.ints.at("exitRow")));
    print(std::to_string(input.ints.at("exitColumn")));
    print(std::to_string(input.ints.at("playerRow")));
    print(std::to_string(input.ints.at("playerColumn")));
    print(input.strings.at("moves"));
    std::cout << input.chars.at("temp") << std::endl;

    return 0;
}