#include "Card.h"
#include <string>

std::string Card::suitToColor(std::string suit){
    if (suit == "Heart" || suit == "Diamond"){
        return "Red";
    }
    else if (suit == "Spade" || suit == "Club"){
        return "Black";
    }
};

Card::Card(){};

Card::Card(int num, std::string suit): number(num), suit(suit) {
    color = suitToColor(suit);
};

int Card::getNumber() const{
    return number;
};

std::string Card::getSuit() const{
    return suit;
};
std::string Card::getColor() const{
    return color;
};