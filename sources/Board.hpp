//
// Created by nir son on 18/05/2021.
//

#ifndef CPP_TASK_4B_BOARD_HPP
#define CPP_TASK_4B_BOARD_HPP

#include <unordered_map>
#include <iostream>
#include "City.hpp"

namespace pandemic {
    class Board {
    public:

        Board();
        ~Board() = default;

        std::unordered_map<City, CityInfo> cities;

        std::unordered_map<Color, bool> cures;

        int& operator[](City city);
        friend std::ostream& operator<<(std::ostream& os, Board& board);
        bool is_clean();
        void remove_cures();
        void remove_stations();

    private:
        void read_cities_from_file(std::istream& cities_file);
    };
}

#endif //CPP_TASK_4B_BOARD_HPP
