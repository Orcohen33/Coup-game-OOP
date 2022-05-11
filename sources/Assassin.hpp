#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Player.hpp"

using namespace std;

namespace coup
{
    class Assassin : public Player
    {
    public:
        Assassin(Game &game, const std::string &name);
        void coup(Player &player) override;
        string role() override;

        /* Help variables and functions */
        bool isCouped = false;
        Player *last_couped_player = nullptr;
    };
}