#ifndef MAZE_HPP
#define MAZE_HPP


#include <string>
#include <vector>

#include "tools.hpp"

#include "Input.hpp"


class Maze {
    public:
        void createMap(const std::string mapStr);
        void printMap();
        void set(const int row, const int column, const char ch);
        std::vector<std::vector<char>> map;
    private:
};


#endif