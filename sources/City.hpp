//
// Created by nir son on 18/05/2021.
//


#ifndef CPP_TASK_4B_CITY_HPP
#define CPP_TASK_4B_CITY_HPP

#include <unordered_set>
#include <unordered_map>
#include "Color.hpp"

namespace pandemic {
    enum City {
        Algiers,
        Atlanta,
        Baghdad,
        Bangkok,
        Beijing,
        Bogota,
        BuenosAires,
        Cairo,
        Chennai,
        Chicago,
        Delhi,
        Essen,
        HoChiMinhCity,
        HongKong,
        Istanbul,
        Jakarta,
        Johannesburg,
        Karachi,
        Khartoum,
        Kinshasa,
        Kolkata,
        Lagos,
        Lima,
        London,
        LosAngeles,
        Madrid,
        Manila,
        MexicoCity,
        Miami,
        Milan,
        Montreal,
        Moscow,
        Mumbai,
        NewYork,
        Osaka,
        Paris,
        Riyadh,
        SanFrancisco,
        Santiago,
        SaoPaulo,
        Seoul,
        Shanghai,
        StPetersburg,
        Sydney,
        Taipei,
        Tehran,
        Tokyo,
        Washington
    };

    struct City_conversions {
        static std::unordered_map<std::string, City> string_city_conversion;
    };

    struct CityInfo {
        std::unordered_set<City> neighbors;
        Color color;
        int disease_level;
        bool has_research_center;
        std::string name;
    };
}
#endif //CPP_TASK_4B_CITY_HPP
