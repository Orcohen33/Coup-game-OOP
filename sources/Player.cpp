#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Player.hpp"

using namespace std;

namespace coup
{
    Player::Player(Game &game, const std::string &name) : name(name), myGame(game)
    {
        const int max_players = 6;
        // Cant add new player if game contains more than 6 players
        if (this->myGame.game_started)
        {
            throw std::runtime_error("Game already started");
        }
        if (this->myGame.players().size() == max_players)
        {
            throw std::runtime_error("Too many players");
        }
        this->myGame.add_player(*this);
    }
    void Player::income()
    {

        this->can_start_game();

        // find the currect index of the player
        auto itr = find(this->myGame.players_vec.begin(), this->myGame.players_vec.end(), this);
        uint index = distance(this->myGame.players_vec.begin(), itr);

        // check if the currect player has the right to income
        if (index == this->myGame.turn_index)
        {
            this->coin += 1;
            this->last_move = "income";
            this->myGame.increase_turn_index();
        }
        else
        {
            throw std::runtime_error("It's not your turn");
        }
    }
    void Player::foreign_aid()
    {
        const int max_coins = 10;
        this->can_start_game();
        if (this->coin < max_coins)
        {
            // find the currect index of the player
            auto itr = find(this->myGame.players_vec.begin(), this->myGame.players_vec.end(), this);
            uint index = distance(this->myGame.players_vec.begin(), itr);

            // check if the currect player has the right to income
            if (index == this->myGame.turn_index)
            {
                this->coin += 2;
                this->last_move = "foreign_aid";
                this->myGame.increase_turn_index();
            }
            else
            {
                throw std::runtime_error("It's not your turn");
            }
        }
        else
        {
            throw std::runtime_error("Player has more than 10 coins");
        }
    }
    // Coup other player , cost 7 coins
    void Player::coup(Player &player)
    {
        const int coup_cost = 7;
        // cout << "Player turn + index: " << this->name << " ," << this->get_index() << endl;
        this->can_start_game();
        if (this->coin >= coup_cost)
        {
            // Check if the currect player has the right to coup
            if (!player.isAlive)
            {
                throw std::runtime_error("Player is not alive");
                return;
            }
            player.isAlive = false;
            this->coin -= coup_cost;
            this->last_move = "coup";
            // this->last_couped_player = &player;
            this->myGame.increase_turn_index();
        }
        else
        {
            throw std::runtime_error("Not enough coins");
        }
    }
    int Player::coins() const
    {
        return this->coin;
    }
    string Player::role()
    {
        return "Player";
    }

    // -------------------------------------- HELP-FUNCTIONS --------------------------------------
    uint Player::get_index()
    {
        auto itr = find(this->myGame.players_vec.begin(), this->myGame.players_vec.end(), this);
        uint index = distance(this->myGame.players_vec.begin(), itr);
        return index;
    }

    void Player::can_start_game()
    {
        if (this->myGame.players_vec.size() < 2)
        {
            throw std::runtime_error("Not enough players");
        }
        if (!this->myGame.game_started)
        {
            this->myGame.game_started = true;
        }
    }
}