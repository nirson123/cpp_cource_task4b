//
// Created by nir son on 18/05/2021.
//

#ifndef CPP_TASK_4B_GENESPLICER_HPP
#define CPP_TASK_4B_GENESPLICER_HPP

#include "Player.hpp"
using namespace std;
namespace pandemic{
    class GeneSplicer : public Player{
    public:
        GeneSplicer(Board& board, City city)
                : Player(board, city){}
        ~GeneSplicer() = default;

        GeneSplicer& discover_cure(Color color) override{
            if(!board.cities[current_city].has_research_center){throw logic_error("no research center");}
            if(cards.size() < 5){throw logic_error("not enough cards");}

            cards.erase(cards.begin(), ++++++++++cards.begin());
            board.cures[color] = true;
            return *this;
        }

        std::string role() override{return "GeneSplicer";}
    };
}

#endif //CPP_TASK_4B_GENESPLICER_HPP
