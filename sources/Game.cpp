#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;

namespace coup
{
    Game::Game()
    {
        this->turn_index = 0; // When the game starts, the first player is the first to play
        this->game_started = false;
    }

    /**
     * @brief This method adds a player to the game
     *
     * @param player
     */
    void Game::add_player(Player &player)
    {
        this->players_vec.push_back(&player);
    }

    /**
     * @brief This method is to return the names of the players
     *
     * @return vector<string>
     */
    vector<string> Game::players()
    {
        vector<string> players_names;
        for (auto *player : this->players_vec)
        {
            if (player->isAlive)
            {
                players_names.push_back(player->name);
            }
        }
        return players_names;
    }
    string Game::turn()
    {
        return this->players_vec[this->turn_index]->name;
    }
    string Game::winner()
    {
        /*
        check if there is only one player alive in the game
        if yes, return the name of the player
        if no, Throw exception with "No winner"
        */
        vector<string> players_names = this->players();
        string winner = "None";
        if (players_names.size() == 1 && this->game_started)
        {
            winner = players_names[0];
        }
        else
        {
            throw std::runtime_error("No winner");
        }
        return winner;
    }

    // ------------------------------------------- HELP-FUNCTIONS -------------------------------------------
    void Game::remove_player(Player &player)
    {
        auto itr = find(this->players_vec.begin(), this->players_vec.end(), &player);
        this->players_vec.erase(itr);
    }

    void Game::increase_turn_index()
    {

        if (this->players().size() > 1)
        {

            // Check if the currect turn index is the last index of player_vec
            if ((this->turn_index + 1) >= this->players_vec.size())
            {
                this->turn_index = 0;

                for (uint i = 0; i < this->players_vec.size(); i++)
                {
                    if (!this->players_vec[i]->isAlive)
                    {
                        this->players_vec.erase(this->players_vec.begin() + i);
                    }
                }
            }
            else
            {
                // Check if the next player is alive
                if (this->players_vec[this->turn_index + 1]->isAlive)
                {
                    this->turn_index += 1;
                }
                // if not then increase index by one and then call increase_turn_index() again
                else
                {
                    this->turn_index += 2;
                    this->increase_turn_index();
                }
            }
        }
    }
}