#include <iostream>
#include <string>
#include <vector>
#include <map>

void print(const std::string str) {
    std::cout << str << std::endl;
}

int main() {
    std::map<std::string, char> chars;

    std::string foo = "h";

    chars["lol"] = foo[0];

    std::cout << chars["lol"] << std::endl;

    // std::map<std::string, int> ints;
    // std::map<std::string, bool> bools;
    // std::map<std::string, std::string> strings;

    // ints["width"] = 4;
    // bools["stupid"] = true;
    // strings["lmao"] = "xd";
    
    // print(std::to_string(ints.at("width")));
    // print(std::to_string(bools.at("stupid")));
    // print(strings.at("lmao"));

    return 0;
}

