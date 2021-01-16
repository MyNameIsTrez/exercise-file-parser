#include "Input.hpp"


void Input::parse(const std::string filename, const std::string format, const char formatDelimiter) {
    std::vector<std::string> fileLines = readIntoLines(filename);

    for (std::string formatLine : split(format, '\n')) {
        std::map<std::string, std::string> instruction = getInstruction(formatLine, formatDelimiter);
 
        std::vector<std::string> varNames = split(instruction.at("vars"), ',');
        int varNamesCount = varNames.size();

        std::vector<std::string> lineNums = split(instruction.at("line"), '-');

        std::vector<std::string> values = getValues(varNamesCount, lineNums, fileLines);
 
        for (int i = 0; i < varNamesCount; i++)
            insert(trim(varNames.at(i)), values.at(i), instruction.at("type"));
    }
}

std::vector<std::string> Input::getValues(const int varNamesCount, const std::vector<std::string>& lineNums, const std::vector<std::string>& fileLines) {
    std::vector<std::string> values;
    int lineNum, lineNumStart, lineNumEnd;

    int lineNumsCount = lineNums.size();
    int fileLinesCount = fileLines.size();

    if (lineNumsCount == 1) {
        lineNum = std::stoi(lineNums.at(0));
        if (lineNum < 1 || lineNum > fileLinesCount)
            throw std::runtime_error("Line number too large or small; can only accept 1 to " + std::to_string(fileLinesCount) + " but was given " + std::to_string(lineNum) + ".");
        values = split(fileLines.at(lineNum - 1));
    } else if (lineNumsCount == 2 && varNamesCount == 1) {
        lineNumStart = std::stoi(lineNums.at(0));
        lineNumEnd = std::stoi(lineNums.at(1));
        if (lineNumStart > lineNumEnd)
            throw std::runtime_error("Start line number was larger than end line number; was given start line " + std::to_string(lineNumStart) + " and end line " + std::to_string(lineNumEnd) + ".");
        else if (lineNumStart < 1 || lineNumEnd > fileLinesCount)
            throw std::runtime_error("End line number too large or small; can only accept 1 to " + std::to_string(fileLinesCount) + " but was given " + std::to_string(lineNumEnd) + ".");

        values.push_back(""); // Need to put something at index 0 for .at(0) += to work.
        for (int i = lineNumStart; i <= lineNumEnd; i++) {
            values.at(0) += fileLines.at(i - 1);
            if (i != lineNumEnd) values.at(0) += '\n';
        }
    } else if (lineNumsCount > 2)
        throw std::runtime_error("Too many line numbers; can only accept 1 or 2 but was given " + std::to_string(lineNumsCount) + ".");
    else if (lineNumsCount == 2 && varNamesCount != 1)
        throw std::runtime_error("Too many vars; can only accept 1 but was given " + std::to_string(varNamesCount) + ".");
    return values;
}

int Input::getInt(const std::string name) {
    if (!ints.count(name)) throwInvalidName(name, "ints");
    return ints[name];
}

double Input::getDouble(const std::string name) {
    if (!doubles.count(name)) throwInvalidName(name, "doubles");
    return doubles[name];
}

std::string Input::getString(const std::string name) {
    if (!strings.count(name)) throwInvalidName(name, "strings");
    return strings[name];
}

bool Input::getBool(const std::string name) {
    if (!bools.count(name)) throwInvalidName(name, "bools");
    return bools[name];
}

char Input::getChar(const std::string name) {
    if (!chars.count(name)) throwInvalidName(name, "chars");
    return chars[name];
}

void Input::throwInvalidName(const std::string name, const std::string mapType) {
    throw std::runtime_error("\"" + name + "\" wasn't found in the " + mapType + " map; check its type and line.");
}

void Input::insert(const std::string name, const std::string value, const std::string type) {
    try {
        if (type == "int") ints[name] = std::stoi(value);
        else if (type == "double") doubles[name] = std::stod(value);
        else if (type == "string") strings[name] = value;
        else if (type == "bool") bools[name] = std::stoi(value) == 1;
        else if (type == "char") chars[name] = value[0];
    } catch (std::invalid_argument& e) {
        throw std::runtime_error("\"" + name + "\"" + " isn't a " + type + ", cause its value was \"" + value + "\".");
    }
}

std::map<std::string, std::string> Input::getInstruction(const std::string formatLine, const char formatDelimiter) {
    std::map<std::string, std::string> instruction;

    bool foundName = false, foundType = false, foundLine = false;
    
    for (std::string untrimmedInstruction : split(formatLine, formatDelimiter)) {
        std::string token = trim(untrimmedInstruction);
        std::vector<std::string> tokenParts = split(token, ':');

        if (tokenParts.size() != 2) throw std::runtime_error("Format instruction key didn't have a (correct) value.");

        std::string key = trim(tokenParts.at(0));
        std::string value = trim(tokenParts.at(1));

        if (key == "vars") foundName = true;
        if (key == "type") foundType = true;
        if (key == "line") foundLine = true;

        instruction[key] = value;
    }
    
    bool validInstruction = foundName && foundType && foundLine;
    if (!validInstruction) throw std::runtime_error("Format instruction keys are missing/wrong.");
    return instruction;
}

std::vector<std::string> Input::readIntoLines(const std::string filename) {
    std::ifstream stream(filename);
    if (!stream.is_open()) throw std::runtime_error("Couldn't open the input file.");
    std::stringstream buffer;
    buffer << stream.rdbuf();
    return split(buffer.str(), '\n');
}