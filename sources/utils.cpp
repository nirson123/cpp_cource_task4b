//
// Created by nir son on 18/05/2021.
//

#include "City.hpp"
#include <string>

using namespace pandemic;

std::unordered_map<std::string, City> City_conversions::string_city_conversion ={
        {"Algiers",       City::Algiers},
        {"Atlanta",       City::Atlanta},
        {"Baghdad",       City::Baghdad},
        {"Bangkok",       City::Bangkok},
        {"Beijing",       City::Beijing},
        {"Bogota",        City::Bogota},
        {"BuenosAires",   City::BuenosAires},
        {"Cairo",         City::Cairo},
        {"Chennai",       City::Chennai},
        {"Chicago",       City::Chicago},
        {"Delhi",         City::Delhi},
        {"Essen",         City::Essen},
        {"HoChiMinhCity", City::HoChiMinhCity},
        {"HongKong",      City::HongKong},
        {"Istanbul",      City::Istanbul},
        {"Jakarta",       City::Jakarta},
        {"Johannesburg",  City::Johannesburg},
        {"Karachi",       City::Karachi},
        {"Khartoum",      City::Khartoum},
        {"Kinshasa",      City::Kinshasa},
        {"Kolkata",       City::Kolkata},
        {"Lagos",         City::Lagos},
        {"Lima",          City::Lima},
        {"London",        City::London},
        {"LosAngeles",    City::LosAngeles},
        {"Madrid",        City::Madrid},
        {"Manila",        City::Manila},
        {"MexicoCity",    City::MexicoCity},
        {"Miami",         City::Miami},
        {"Milan",         City::Milan},
        {"Montreal",      City::Montreal},
        {"Moscow",        City::Moscow},
        {"Mumbai",        City::Mumbai},
        {"NewYork",       City::NewYork},
        {"Osaka",         City::Osaka},
        {"Paris",         City::Paris},
        {"Riyadh",        City::Riyadh},
        {"SanFrancisco",  City::SanFrancisco},
        {"Santiago",      City::Santiago},
        {"SaoPaulo",      City::SaoPaulo},
        {"Seoul",         City::Seoul},
        {"Shanghai",      City::Shanghai},
        {"StPetersburg",  City::StPetersburg},
        {"Sydney",        City::Sydney},
        {"Taipei",        City::Taipei},
        {"Tehran",        City::Tehran},
        {"Tokyo",         City::Tokyo},
        {"Washington",    City::Washington}
};

std::unordered_map<std::string, Color> Color_conversions::string_color_conversion = {
        {"Black", Color::Black},
        {"Yellow", Color::Yellow},
        {"Blue", Color::Blue},
        {"Red", Color::Red}
};
std::unordered_map<Color, std::string> Color_conversions::color_string_conversion{
        {Color::Black, "Black"},
        {Color::Yellow,"Yellow"},
        {Color::Blue, "Blue"},
        {Color::Red, "Red"}
};
