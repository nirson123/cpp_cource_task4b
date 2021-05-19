//
// Created by nir son on 18/05/2021.
//

#include <set>
#include "Player.hpp"

using namespace std;
using namespace pandemic;


Player::Player(Board& board, City city)
: board(board), current_city(city){}

pandemic::Player& pandemic::Player::drive(pandemic::City city) {
    if(board.cities[current_city].neighbors.find(city) == board.cities[current_city].neighbors.end()){throw invalid_argument{"not a neighbor!"};}

    current_city = city;
    return *this;
}

pandemic::Player& pandemic::Player::fly_direct(pandemic::City city) {
    if(city == current_city){throw invalid_argument("cant fly from city to itself");}
    if(cards.find(city) == cards.end()){throw invalid_argument{"player dont have the right card"};}

    cards.erase(city);
    current_city = city;
    return *this;
}

pandemic::Player& pandemic::Player::fly_charter(pandemic::City city) {
    if(city == current_city){throw invalid_argument("cant fly from city to itself");}
    if(cards.find(current_city) == cards.end()){throw invalid_argument{"player dont have the right card"};}

    cards.erase(current_city);
    current_city = city;
    return *this;
}

pandemic::Player& pandemic::Player::fly_shuttle(pandemic::City city) {
    if(city == current_city){throw invalid_argument("cant fly from city to itself");}
    if(!board.cities[current_city].has_research_center || !board.cities[city].has_research_center){throw invalid_argument{"no research center"};}

    current_city = city;
    return *this;
}

pandemic::Player& pandemic::Player::build() {
    if(cards.find(current_city) == cards.end()){throw invalid_argument{"player dont have the right card"};}

    if(!board.cities[current_city].has_research_center){
        cards.erase(current_city);
        board.cities[current_city].has_research_center = true;
    }
    return *this;
}

pandemic::Player& pandemic::Player::discover_cure(pandemic::Color color) {
    if(!board.cities[current_city].has_research_center){throw logic_error{"no research center"};}

    static const int needed_cards = 5;

    set<City> card_to_remove{};
    for(const auto& city : cards){
        if(board.cities[city].color == color){
            card_to_remove.insert(city);
        }
        if(card_to_remove.size() == needed_cards){break;}
    }

    if(card_to_remove.size() != needed_cards){throw invalid_argument{"not enough cards"};}
    if(board.cures[color]){return *this;}
    for(const City& c : card_to_remove){cards.erase(c);}
    board.cures[color] = true;
    return *this;
}

pandemic::Player& pandemic::Player::treat(pandemic::City city) {
    if(city != current_city || board[city] == 0){throw invalid_argument{"cant treat given city"};}

    if(board.cures[board.cities[current_city].color]){board[city] = 0;}
    else{board[city] --;}
    return *this;
}

pandemic::Player& pandemic::Player::take_card(pandemic::City city) {
    cards.insert(city);
    return *this;
}

pandemic::Player& pandemic::Player::remove_cards() {
    cards.clear();
    return *this;
}

std::string Player::role() {
    return "";
}

