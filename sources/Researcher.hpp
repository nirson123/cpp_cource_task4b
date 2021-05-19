//
// Created by nir son on 18/05/2021.
//

#ifndef CPP_TASK_4B_RESEARCHER_HPP
#define CPP_TASK_4B_RESEARCHER_HPP

#include "Player.hpp"
#include <set>

using namespace std;
namespace pandemic{
    class Researcher : public Player{
    public:
        Researcher(Board& board, City city)
                : Player(board, city){}
        ~Researcher() = default;

        Researcher& discover_cure(Color color) override {
            set<City> card_to_remove{};
            for(const auto& city : cards){
                if(board.cities[city].color == color){
                    card_to_remove.insert(city);
                }
                if(card_to_remove.size() == 5){break;}
            }

            if(card_to_remove.size() != 5){throw invalid_argument("not enough cards");}
            if(board.cures[color]){return *this;}
            for(const City& c : card_to_remove){cards.erase(c);}
            board.cures[color] = true;
            return *this;
        }

        std::string role() override{return "Researcher";}
    };
}

#endif //CPP_TASK_4B_RESEARCHER_HPP
