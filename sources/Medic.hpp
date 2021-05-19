//
// Created by nir son on 18/05/2021.
//

#ifndef CPP_TASK_4B_MEDIC_HPP
#define CPP_TASK_4B_MEDIC_HPP

#include "Player.hpp"

namespace pandemic{
    class Medic : public Player{
    public:
        Medic(Board& board, City city)
                : Player(board, city){}
        ~Medic() = default;

        Medic& treat(City city) override {
            if(city != current_city || board[city] == 0){throw invalid_argument("cant treat given city");}

            board[city] = 0;
            return *this;
        }

        Medic& drive(City city) override{
            this->Player::drive(city);
            if(board.cures[board.cities[current_city].color]){board[current_city] = 0;}
            return *this;
        }
        Medic& fly_direct(City city) override{
            this->Player::fly_direct(city);
            if(board.cures[board.cities[current_city].color]){board[current_city] = 0;}
            return  *this;
        }
        Medic& fly_charter(City city) override{
            this->Player::fly_charter(city);
            if(board.cures[board.cities[current_city].color]){board[current_city] = 0;}
            return  *this;
        }
        Medic& fly_shuttle(City city) override{
            this->Player::fly_shuttle(city);
            if(board.cures[board.cities[current_city].color]){board[current_city] = 0;}
            return  *this;
        }

        std::string role() override{return "Medic";}
    };
}

#endif //CPP_TASK_4B_MEDIC_HPP
