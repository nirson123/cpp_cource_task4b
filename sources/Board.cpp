//
// Created by nir son on 18/05/2021.
//

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <fstream>
#include <sstream>

using namespace std;
using namespace pandemic;


void pandemic::Board::read_cities_from_file(std::istream& cities_file) {

    string name;
    string color;
    string nei;
    string line;

    while(getline(cities_file, line)){  // for each city
        istringstream line_stream{line};
        line_stream >> name >> color;

        // update the fields
        City city = City_conversions::string_city_conversion[name];
        cities[city].color = Color_conversions::string_color_conversion[color];
        cities[city].has_research_center = false;
        cities[city].disease_level = 0;
        cities[city].name = name;

        // update the neighbors
        while(line_stream >> nei){
            cities[city].neighbors.insert(City_conversions::string_city_conversion[nei]);
        }
    }
}

int& pandemic::Board::operator[](City city) {
    if(cities.find(city) == cities.end()){throw invalid_argument{"city not on board"};}

    return cities[city].disease_level;
}


std::ostream& pandemic::operator<<(std::ostream& os, pandemic::Board& board) {

    // print disease levels
    os << "cities with disease:" << endl;
    for(const auto& [city, city_info] : board.cities){
        if(board[city] > 0){os << city_info.name << " : " << board[city] << endl;}
    }
    os << "the rest of the cities are clean!" << endl << endl;

    // print cures
    os << "discovered cures:" << endl;
    for(const auto& [color, is_found] : board.cures){
        if(is_found){os << Color_conversions::color_string_conversion[color] << "  ";}
    }
    os << endl << endl;

    // print research centers
    os  << "research centers build:" << endl;
    for(const auto& [city, city_info] : board.cities){
        if(city_info.has_research_center){os << city_info.name << "  ";}
    }
    os << endl << endl;
    return os;
}

bool pandemic::Board::is_clean() {
    for(const auto& [city, city_info] : cities){
        if(city_info.disease_level > 0){return false;}
    }
    return true;
}

void pandemic::Board::remove_cures() {
    cures[Color::Black] = false;
    cures[Color::Yellow] = false;
    cures[Color::Blue] = false;
    cures[Color::Red] = false;
}

void pandemic::Board::remove_stations() {
    for(auto& [city, city_info] : cities){
        city_info.has_research_center = false;
    }
}

Board::Board() {
    // read the board layout from a file
    ifstream cities_file{"cities_map.txt"};
    if(!cities_file.is_open()){exit(1);}
    read_cities_from_file(cities_file);
    cities_file.close();

    //initiate the cures
    cures[Color::Black] = false;
    cures[Color::Yellow] = false;
    cures[Color::Blue] = false;
    cures[Color::Red] = false;
}


