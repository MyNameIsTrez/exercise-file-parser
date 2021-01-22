#include "Maze.hpp"


void Maze::createMap(const std::string mapStr, const int allegedWidth, const int allegedHeight) {
    std::vector<std::string> mapRowStr = split(mapStr, '\n');

    mazeHeight = mapRowStr.size();
    mazeWidth = mapRowStr.at(0).size();

    if (mazeHeight != allegedHeight || mazeWidth != allegedWidth)
        err("could not read maze layout");

    for (int rowIdx = 0; rowIdx < mazeHeight; rowIdx++) {
        std::string rowStr = mapRowStr.at(rowIdx);
        std::vector<char> rowVector;

        for (int colIdx = 0; colIdx < mazeWidth; colIdx++) {
            char ch = rowStr.at(colIdx);
            if (ch != emptyIcon && ch != wallIcon) err("could not read maze layout");
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
    set(exitRow, exitColumn, EXIT);
}


void Maze::setPlayer(const int row, const int column) {
    playerRow = row;
    playerColumn = column;
    set(playerRow, playerColumn, PLAYER);
}


char Maze::get(const int row, const int column) {
    return map.at(row).at(column);
}


void Maze::set(const int row, const int column, const Tile tile) {
    if (row < 0 || row >= mazeHeight || column < 0 || column >= mazeWidth || get(row, column) == getTileIcon(WALL)) {
        err(getTileName(tile) + " outside maze or off the path");
    } else
        map.at(row).at(column) = getTileIcon(tile);
}


// The only reason this function exists is because my maze assignment wants me to evaluate
// if the movement string is valid before printing the initial map.
void Maze::getMoveOffsetPlayer(const std::string movesStr, int& dx, int& dy) {
    for (int i = 0; i < movesStr.size(); i++) {
        char ch = movesStr.at(i);
        switch(tolower(ch)) {
            case 'u': dy--; break;
            case 'd': dy++; break;
            case 'l': dx--; break;
            case 'r': dx++; break;
            default: err("invalid move");
        }
    }
}


void Maze::movePlayer(const int dx, const int dy) {
    if (!(dx == 0 && dy == 0)) {
        set(playerRow, playerColumn, EMPTY);
        playerColumn += dx;
        playerRow += dy;
        set(playerRow, playerColumn, PLAYER);
    }
}


char Maze::getTileIcon(const Tile tile) {
    switch(tile) {
        case EXIT: return exitIcon;
        case PLAYER: return playerIcon;
        case EMPTY: return emptyIcon;
        case WALL: return wallIcon;
    }
    err("getTileIcon() didn't get a valid value");
    return ' '; // Gets rid of compiler warning that the function doesn't necessarily return.
}


std::string Maze::getTileName(const Tile tile) {
    switch(tile) {
        case EXIT: return "exit";
        case PLAYER: return "player";
        case EMPTY: return "empty";
        case WALL: return "wall";
    }
    err("getTileName() didn't get a valid value");
    return ""; // Gets rid of compiler warning that the function doesn't necessarily return.
}


void Maze::go(const std::string movesStr) {
    int dx = 0, dy = 0;
    getMoveOffsetPlayer(movesStr, dx, dy);
    printMap();
    movePlayer(dx, dy);
    printMap();
    checkReachedExit();
}


void Maze::checkReachedExit() {
    if (playerRow == exitRow && playerColumn == exitColumn) {
        print("The player reached the exit!");
    } else {
        print("The player did not reach the exit.");
    }
}