#ifndef MAZE_HPP
#define MAZE_HPP


#include <string>
#include <vector>

#include "tools.hpp"


class Maze {
    public:
        void go(const std::string movesStr);
        void createMap(const std::string mapStr, const int allegedWidth, const int allegedHeight);
        void setExit(const int row, const int column);
        void setPlayer(const int row, const int column);

        enum Tile { PLAYER, EXIT, EMPTY, WALL };

        std::vector<std::vector<char>> map;
    private:
        void set(const int row, const int column, const Tile tile);
        char get(const int row, const int column);
        char getTileIcon(const Tile tile);
        std::string getTileName(const Tile tile);
        void getMoveOffsetPlayer(const std::string movesStr, int& dx, int& dy);
        void movePlayer(const int dx, const int dy);
        void printMap();
        void checkReachedExit();

        int exitColumn, exitRow;
        int playerColumn, playerRow;

        char exitIcon = 'x';
        char playerIcon = 'P';
        char emptyIcon = '.';
        char wallIcon = 'l';

        int mazeWidth;
        int mazeHeight;
};


#endif