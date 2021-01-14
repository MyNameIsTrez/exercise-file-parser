// g++ -I include src/* main.c++ && ./a.out

#include "print.hpp"

#include "Input.hpp"
#include "Maze.hpp"


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


    Maze maze;

    maze.createMap(input.getString("maze"));

    return 0;
}