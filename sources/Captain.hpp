#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Player.hpp"

using namespace std;

namespace coup
{
    class Captain : public Player
    {
    public:
        Captain(Game &game, const std::string &name);
        void steal(Player &player);
        static void block(Player &player);
        string role() override;

        /* Help variables and functions */
        Player *last_steal_player;
        int last_steal_coin;
    };
}