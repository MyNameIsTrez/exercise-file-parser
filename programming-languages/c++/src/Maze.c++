#include "Maze.hpp"


void Maze::createMap(const std::string mapStr) {
    std::vector<std::string> mapRowStr = split(mapStr, '\n');

    for (int rowIdx = 0; rowIdx < mapRowStr.size(); rowIdx++) {
        std::string rowStr = mapRowStr.at(rowIdx);
        std::vector<char> rowVector;

        for (int colIdx = 0; colIdx < rowStr.size(); colIdx++) {
            char ch = rowStr.at(colIdx);
            rowVector.push_back(ch);
        }
        map.push_back(rowVector);
    }
}


void Maze::set(const int row, const int column, const char ch) {
    map.at(row).at(column) = ch;
}


void Maze::printMap() {
    for (int rowIdx = 0; rowIdx < map.size(); rowIdx++) {
        for (int colIdx = 0; colIdx < map.at(rowIdx).size(); colIdx++) {
            char ch = map.at(rowIdx).at(colIdx);
            std::cout << ch;
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}