#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#pragma once
using namespace std;

namespace coup
{
    class Player;
    class Game
    {
    public:
        Game();
        vector<string> players();
        vector<Player *> players_vec;
        string turn();
        string winner();
        void add_player(Player &player);
        void remove_player(Player &player);
        void increase_turn_index();

        uint turn_index;
        bool game_started = false;

    private:
    };
}