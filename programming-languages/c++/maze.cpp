// g++ -I include src/* maze.cpp && clear && ./a.out "../../test-input.txt"


#include "tools.hpp"

#include "Input.hpp"
#include "Maze.hpp"


int main(const int argc, const char* argv[]) {
    std::string filename;
    if (argc > 1)
        filename = argv[1];
    else
        err("no input file name given");


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

    input.parse(filename, format, '|');


    // if (Input.getInt(width))


    Maze maze;
    maze.createMap(input.getString("maze"));

    maze.setExit(input.getInt("exitRow"), input.getInt("exitColumn"));
    maze.setPlayer(input.getInt("playerRow"), input.getInt("playerColumn"));
    
    maze.printMap();

    maze.movePlayer(input.getString("moves"));

    maze.printMap();

    maze.checkReachedExit();

    return 0;
}