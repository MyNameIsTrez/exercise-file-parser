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
        void setExit(const int row, const int column);
        void setPlayer(const int row, const int column);
        void movePlayer(const std::string movesStr);

        std::vector<std::vector<char>> map;
    private:
        void set(const int row, const int column, const char ch);
        
        int exitColumn, exitRow;
        int playerColumn, playerRow;

        char exitIcon = 'x';
        char playerIcon = 'P';
        char emptyIcon = '.';
};


#endif