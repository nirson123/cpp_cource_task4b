//
// Created by nir son on 18/05/2021.
//

#ifndef CPP_TASK_4B_FIELDDOCTOR_HPP
#define CPP_TASK_4B_FIELDDOCTOR_HPP

#include "Player.hpp"
using namespace std;
namespace pandemic{
    class FieldDoctor : public Player{
    public:

        FieldDoctor(Board& board, City city)
                : Player(board, city){}
        ~FieldDoctor() = default;

        FieldDoctor& treat(City city) override{
            if((city != current_city &&
            board.cities[current_city].neighbors.find(city) == board.cities[current_city].neighbors.end())||
            board[city] == 0){throw invalid_argument("cant treat given city");}

            if(board.cures[board.cities[city].color]){board[city] = 0;}
            else{board[city] --;}
            return *this;
        }

        std::string role() override{return "FieldDoctor";}
    };
}

#endif //CPP_TASK_4B_FIELDDOCTOR_HPP
