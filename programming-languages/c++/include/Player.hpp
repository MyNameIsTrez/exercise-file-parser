#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <vector>


class Player {
    public:
        void move(const char c, const std::vector<std::vector<int>>& map);
    private:
        int x;
        int y;
};


#endif