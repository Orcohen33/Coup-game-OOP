#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Player.hpp"

using namespace std;

namespace coup
{
    class Duke : public Player
    {
    public:
        Duke(Game &game, const std::string &name); // Constructur for Duke
        void tax();                                // Can loot 3 coins
        static void block(Player &player);         // Can block foreign aid
        string role() override;                    // Return "Duke"
    };
}