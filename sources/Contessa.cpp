#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Contessa.hpp"
#include "Assassin.hpp"
using namespace std;

/* Help function to check if player is instanceof other class */
template <typename Base, typename T>
inline bool instanceof (const T *ptr)
{
    return dynamic_cast<const Base *>(ptr) != nullptr;
}

namespace coup
{
    coup::Contessa::Contessa(Game &game, const std::string &name) : Player(game, name) {}
    void Contessa::block(Player &player)
    {
        // Check if player is type of Assassin
        if (instanceof <Assassin>(&player) && player.last_move == "coup3")
        {
            dynamic_cast<Assassin &>(player).last_couped_player->isAlive = true;
        }
        else
        {
            throw std::runtime_error("Player's last move is not coup(3 coins) || Player is not Assassin");
        }
    };
    string Contessa::role()
    {
        return "Contessa";
    };
}