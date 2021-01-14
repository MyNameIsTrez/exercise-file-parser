#include "Player.hpp"


Player::Player(const int rowStart, const int columnStart, Maze& maze) {
    x = columnStart;
    y = rowStart;
    maze.set(rowStart, columnStart, icon);
}


void Player::move(const std::string movesStr, const std::vector<std::vector<char>>& map, Maze& maze) {
    int dx = 0;
    int dy = 0;
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
        moveStep(dx, dy, maze);
    }
}

void Player::moveStep(const int dx, const int dy, Maze& maze) {
    maze.set(y, x, '.');
    x += dx;
    y += dy;
    maze.set(y, x, icon);
}