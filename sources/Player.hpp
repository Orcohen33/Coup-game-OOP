#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Game.hpp"

#pragma once

using namespace std;

namespace coup
{
    class Player
    {

    public:
        Player(Game &game, const string &name);
        void income();
        void foreign_aid();
        virtual void coup(Player &player);
        int coins() const;         // getter
        virtual string role() = 0; // getter
        int coin = 0;
        string name;
        Game &myGame;

        /* Help variables and functions */
        string last_move = "";
        // Player *last_couped_player = nullptr;
        bool isAlive = true;
        uint get_index(); // getter
        void can_start_game();
    };
}