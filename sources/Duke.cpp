#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Duke.hpp"

using namespace std;

namespace coup
{
    /*
    Constructor for Duke
    */
    Duke::Duke(Game &game, const std::string &name) : Player(game, name){};

    void Duke::tax()
    {
        this->coin += 3;
        this->myGame.increase_turn_index();
    };

    // Can block foreign aid
    void Duke::block(Player &player)
    {
        // Check if player's last_move is foreign_aid
        if (player.last_move == "foreign_aid")
        {
            player.coin -= 2;
        }
        else
        {
            throw std::runtime_error("Player's last move is not foreign_aid");
        }
    };

    string Duke::role()
    {
        return "Duke";
    };
}