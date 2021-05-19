//
// Created by nir son on 18/05/2021.
//

#ifndef CPP_TASK_4B_VIROLOGIST_HPP
#define CPP_TASK_4B_VIROLOGIST_HPP

#include "Player.hpp"

namespace pandemic{
    class Virologist : public Player{
    public:
        Virologist(Board& board, City city)
                : Player(board, city){}
        ~Virologist() = default;

        Virologist& treat(City city) override{
            if(board[city] == 0){throw invalid_argument{"cant treat given city"};}
            if(city != current_city){
                if(cards.find(city) == cards.end()){throw invalid_argument{"cant treat given city"};}
                cards.erase(city);
            }

            if(board.cures[board.cities[city].color]){board[city] = 0;}
            else{board[city] --;}
            return *this;
        }

        std::string role() override{return "Virologist";}
    };
}

#endif //CPP_TASK_4B_VIROLOGIST_HPP
