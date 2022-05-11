#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Player.hpp"

using namespace std;

namespace coup
{
    class Contessa : public Player
    {
    public:
        Contessa(Game &game, const std::string &name);
        static void block(Player &player);
        string role() override;
    };
}