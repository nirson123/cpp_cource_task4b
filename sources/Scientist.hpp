//
// Created by nir son on 18/05/2021.
//

#ifndef CPP_TASK_4B_SCIENTIST_HPP
#define CPP_TASK_4B_SCIENTIST_HPP

#include "Player.hpp"
#include <set>

using namespace std;
namespace pandemic{
    class Scientist : public Player{
    public:
        int n;

        Scientist(Board& board, City city, int n)
                : Player(board, city), n(n){}
        ~Scientist() = default;

        Scientist& discover_cure(Color color) override{
            if(!board.cities[current_city].has_research_center){throw logic_error("no research center");}

            set<City> card_to_remove{};
            for(const auto& city : cards){
                if(card_to_remove.size() == n){break;}
                if(board.cities[city].color == color){
                    card_to_remove.insert(city);
                }
            }

            if(card_to_remove.size() != n){throw invalid_argument("not enough cards");}

            for(const City& c : card_to_remove){cards.erase(c);}
            board.cures[color] = true;
            return *this;
        }
        std::string role() override{return "Scientist";}
    };
}

#endif //CPP_TASK_4B_SCIENTIST_HPP
