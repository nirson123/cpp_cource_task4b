//
// Created by nir son on 18/05/2021.
//

#ifndef CPP_TASK_4B_DISPATCHER_HPP
#define CPP_TASK_4B_DISPATCHER_HPP

namespace pandemic{
    class Dispatcher : public Player{
    public:
        Dispatcher(Board& board, City city)
                : Player(board, city){}
        ~Dispatcher() = default;

        Dispatcher& fly_direct(City city) override {
            if(city == current_city){throw invalid_argument("cant fly from city to itself");}
            if (!board.cities[current_city].has_research_center) {
                if (cards.find(city) == cards.end()) { throw invalid_argument("player dont have the right card"); }
                cards.erase(city);
            }
            current_city = city;
            return *this;
        }
        std::string role() override{return "Dispatcher";}
    };
}

#endif //CPP_TASK_4B_DISPATCHER_HPP
