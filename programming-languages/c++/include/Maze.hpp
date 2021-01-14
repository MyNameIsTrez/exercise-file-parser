#ifndef MAZE_HPP
#define MAZE_HPP


#include <string>
#include <vector>


class Maze {
    public:
        void createMap(const std::string mapStr);
        void printMap();
    private:
        std::vector<std::vector<char>> map;
};


#endif