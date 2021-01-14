#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <string>
#include <vector>

#include "tools.hpp"

#include "Maze.hpp"


class Player {
    public:
        Player(const int rowStart, const int columnStart, Maze& maze);

        void move(const std::string movesStr, const std::vector<std::vector<char>>& map, Maze& maze);
    private:
        void moveStep(const int dx, const int dy, Maze& maze);

        int x;
        int y;
        char icon = 'P';
};


#endif