//
// Created by nir son on 18/05/2021.
//

#ifndef CPP_TASK_4B_COLOR_HPP
#define CPP_TASK_4B_COLOR_HPP

#include <unordered_map>

namespace pandemic {
    enum Color {
        Black,
        Yellow,
        Blue,
        Red
    };

    struct Color_conversions{
        static std::unordered_map<std::string, Color> string_color_conversion;
        static std::unordered_map<Color, std::string> color_string_conversion;
    };


}
#endif //CPP_TASK_4B_COLOR_HPP
