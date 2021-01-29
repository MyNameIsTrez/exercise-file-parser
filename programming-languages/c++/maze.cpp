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

    /* The reason why this program has so many lines of code is because I wanted it to be able to read any arbitrarily formatted input file.
       This input file could have arbitrary variable names, variable types and line(s) that are easily specified by the user.
       I achieved this with the "format" string below that tells the program how the file should be parsed.

       The reason I didn't want to hardcode these things is because I know that for a few of my future university exercises
       I'll also need to parse input files in a very similar fashion, so I wanted to make this program as reusable as possible.
    */

    std::string format =
    " vars : height , width | type:int \n"
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