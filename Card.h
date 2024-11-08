#ifndef CARD_H
#define CARD_H

#include <string>

class Card{
private:
    int number;
    std::string suit;
    std::string color;

    std::string suitToColor(std::string suit);

public:
    Card();

    Card(int num,std::string suit);

    int getNumber() const;
    std::string getSuit() const;
    std::string getColor() const;
};

#endif