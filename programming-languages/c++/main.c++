// g++ -Iinclude src/Input.c++ main.c++ && ./a.out


#include "Input.hpp"


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


int main() {
    Input input;

    std::string format =
    " vars : height , width | type : int | line : 1 \n"
    " vars : maze | type : string | line:  2   -  5 \n"
    "vars:exitRow,exitColumn|type:int|line:6\n"
    "vars:playerRow,playerColumn|type:int|line:7\n"
    "vars:moves|type:string|line:8\n"
    "vars:TEMPBOOL|type:bool|line:7\n"
    "vars:TEMPDOUBLE|type:double|line:1\n"
    "vars:TEMPCHAR|type:char|line:8";

    input.parse("../../test-input.txt", format, '|');

    print(input.getInt("height"));
    print(input.getInt("width"));
    print(input.getString("maze"));
    print(input.getInt("exitRow"));
    print(input.getInt("exitColumn"));
    print(input.getInt("playerRow"));
    print(input.getInt("playerColumn"));
    print(input.getString("moves"));
    print(input.getBool("TEMPBOOL"));
    print(input.getDouble("TEMPDOUBLE"));
    print(input.getChar("TEMPCHAR"));

    return 0;
}