//
// Created by nir son on 18/05/2021.
//

#ifndef CPP_TASK_4B_OPERATIONSEXPERT_HPP
#define CPP_TASK_4B_OPERATIONSEXPERT_HPP

#include "Player.hpp"

namespace pandemic{
    class OperationsExpert : public Player{
        public:
        OperationsExpert(Board& board, City city)
        : Player(board, city){}
        ~OperationsExpert() = default;

        OperationsExpert& build() override{
            if(!board.cities[current_city].has_research_center){
                cards.erase(current_city);
                board.cities[current_city].has_research_center = true;
            }
            return *this;
        }
        std::string role() override{return "OperationsExpert";}
    };
}
#endif //CPP_TASK_4B_OPERATIONSEXPERT_HPP
