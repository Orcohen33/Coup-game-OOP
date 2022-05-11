#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Ambassador.hpp"
#include "Captain.hpp"
using namespace std;

template <typename Base, typename T>
inline bool instanceof (const T *ptr)
{
    return dynamic_cast<const Base *>(ptr) != nullptr;
}
namespace coup
{
    Ambassador::Ambassador(Game &game, const std::string &name) : Player(game, name) {}
    void Ambassador::transfer(Player &player1, Player &player2)
    {
        if (player1.coin >= 1)
        {
            player1.coin -= 1;
            player2.coin += 1;
            this->myGame.increase_turn_index();
        }
        else
        {
            throw std::runtime_error("Player 1 has no coins");
        }
    };
    void Ambassador::block(Player &player)
    {
        if (instanceof <Captain>(&player) && player.last_move == "steal")
        {
            player.coin -= dynamic_cast<Captain &>(player).last_steal_coin;
            dynamic_cast<Captain &>(player).last_steal_player->coin += dynamic_cast<Captain &>(player).last_steal_coin;
        }
        else
        {
            throw std::runtime_error("Player's last move is not steal || Player is not Captain");
        }
    };
    string Ambassador::role()
    {
        return "Ambassador";
    };
}