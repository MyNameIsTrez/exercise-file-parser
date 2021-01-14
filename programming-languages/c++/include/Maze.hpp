#ifndef MAZE_HPP
#define MAZE_HPP


#include <string>
#include <vector>


class Maze {
    public:
        void createMap(std::string mapStr);
        void print();
    private:
        std::vector<std::vector<int>> map;
};


#endif