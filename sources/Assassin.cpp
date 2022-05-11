#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Assassin.hpp"

using namespace std;

namespace coup
{
    Assassin::Assassin(Game &game, const std::string &name) : Player(game, name) {}
    void Assassin::coup(Player &player)
    {
        const int min_coup_cost = 3;
        const int max_coup_cost = 7;
        if (this->coin >= min_coup_cost && this->coin < max_coup_cost)
        {
            // Check if player already dead
            if (!player.isAlive)
            {
                throw std::runtime_error("Player is not alive");
            }

            player.isAlive = false;
            this->coin -= min_coup_cost;
            this->isCouped = true;
            this->last_move = "coup3";
            this->last_couped_player = &player;
            this->myGame.increase_turn_index();
        }
        else if (this->coin >= max_coup_cost)
        {
            player.isAlive = false;
            this->coin -= max_coup_cost;
            this->isCouped = true;
            this->last_move = "coup7";
            this->last_couped_player = &player;
            this->myGame.increase_turn_index();
        }
        else if (this->coin < min_coup_cost)
        {
            throw std::runtime_error("Not enough coins");
        }
    };
    string Assassin::role()
    {
        return "Assassin";
    };
}