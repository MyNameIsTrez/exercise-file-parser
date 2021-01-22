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
    " vars : height , width | type:int\n"
    "vars:maze|type:string|multiline\n"
    "vars:exitRow,exitColumn|type:int\n"
    "vars:playerRow,playerColumn|type:int\n"
    "vars:moves|type:string";

    input.parse(filename, format);


    Maze maze;
    maze.createMap(input.getString("maze"), input.getInt("width"), input.getInt("height"));

    maze.setExit(input.getInt("exitRow"), input.getInt("exitColumn"));
    maze.setPlayer(input.getInt("playerRow"), input.getInt("playerColumn"));

    maze.go(input.getString("moves"));

    return 0;
}