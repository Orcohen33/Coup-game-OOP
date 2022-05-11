#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Captain.hpp"

using namespace std;

/* Help function to check if player is instanceof other class */
template <typename Base, typename T>
inline bool instanceof (const T *ptr)
{
    return dynamic_cast<const Base *>(ptr) != nullptr;
}

namespace coup
{
    Captain::Captain(Game &game, const std::string &name) : Player(game, name)
    {
        this->last_steal_player = nullptr;
        this->last_steal_coin = 0;
    }

    /**
     * @brief This method steals a coin from another player
     *
     * @param player
     */
    void Captain::steal(Player &player)
    {
        // find the currect index of the player
        auto itr = find(this->myGame.players_vec.begin(), this->myGame.players_vec.end(), this);
        uint index = distance(this->myGame.players_vec.begin(), itr);

        if (index == this->myGame.turn_index)
        {

            if (player.coin >= 2)
            {
                player.coin -= 2;
                this->coin += 2;
                this->last_steal_coin = 2;
            }
            else if (player.coin == 1)
            {
                player.coin -= 1;
                this->coin += 1;
                this->last_steal_coin = 1;
            }
            else
            {
                this->last_steal_coin = 0;
            }
            this->last_move = "steal";
            this->last_steal_player = &player;
            this->myGame.increase_turn_index();
        }
        else
        {
            throw std::runtime_error("It's not your turn");
        }
    };
    /**
     * @brief This method is to block a player(Captain) steal method
     *
     * @param player
     */
    void Captain::block(Player &player)
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
    string Captain::role()
    {
        return "Captain";
    };
}