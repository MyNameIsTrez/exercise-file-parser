#include "tools.hpp"

#include "Maze.hpp"


void Maze::createMap(const std::string mapStr) {
    std::vector<std::string> mapRowStr = split(mapStr, '\n');

    for (int rowIdx = 0; rowIdx < mapRowStr.size(); rowIdx++) {
        std::vector<char> rowVector;
        for (int colIdx = 0; colIdx < mapRowStr.size(); colIdx++) {
            char ch = mapRowStr.at(rowIdx).at(colIdx);
            rowVector.push_back(ch);
        }
        map.push_back(rowVector);
    }
}

void Maze::printMap() {
    for (int rowIdx = 0; rowIdx < map.size(); rowIdx++) {
        for (int colIdx = 0; colIdx < map.at(rowIdx).size(); colIdx++) {
            char ch = map.at(rowIdx).at(colIdx);
            std::cout << ch;
        }
        std::cout << "\n";
    }
}