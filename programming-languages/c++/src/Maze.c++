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


void Maze::setExit(const int row, const int column) {
    exitRow = row;
    exitColumn = column;
    set(exitRow, exitColumn, exitIcon);
}


void Maze::setPlayer(const int row, const int column) {
    playerRow = row;
    playerColumn = column;
    set(playerRow, playerColumn, playerIcon);
}


void Maze::set(const int row, const int column, const char ch) {
    map.at(row).at(column) = ch;
}


void Maze::movePlayer(const std::string movesStr) {
    int dx = 0, dy = 0;
    for (int i = 0; i < movesStr.size(); i++) {
        char ch = movesStr.at(i);
        switch(tolower(ch)) {
            case 'u': dy--; break;
            case 'd': dy++; break;
            case 'l': dx--; break;
            case 'r': dx++; break;
            default: err("invalid move"); break;
        }
    }
    if (!(dx == 0 && dy == 0)) {
        set(playerRow, playerColumn, emptyIcon);
        playerColumn += dx;
        playerRow += dy;
        set(playerRow, playerColumn, playerIcon);
    }
}