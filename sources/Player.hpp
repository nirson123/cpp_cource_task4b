//
// Created by nir son on 18/05/2021.
//

#ifndef CPP_TASK_4B_PLAYER_HPP
#define CPP_TASK_4B_PLAYER_HPP

#include "Board.hpp"
#include "City.hpp"
#include <unordered_set>
#include <string>

namespace pandemic {
    class Player {
    protected:
        Player(Board& board, City city);
        ~Player() = default;

        Board& board;
        std::unordered_set<City> cards;
        City current_city;
    public:
        virtual Player& drive(City city);
        virtual Player& fly_direct(City city);
        virtual Player& fly_charter(City city);
        virtual Player& fly_shuttle(City city);

        virtual Player& build();
        virtual Player& discover_cure(Color color);
        virtual Player& treat(City city);

        virtual std::string role();
        Player& take_card(City city);
        Player& remove_cards();





    };
}

#endif //CPP_TASK_4B_PLAYER_HPP
