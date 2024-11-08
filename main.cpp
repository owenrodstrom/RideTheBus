#include <string>
#include <random>
#include <iostream>
#include <vector>
#include "Card.h"

std::string getSuit(int suitNum){
    std::string suit;
    if (suitNum == 1){
        suit = "Diamond";
    }
    else if (suitNum == 2){
        suit = "Heart";
    }
    else if (suitNum == 3){
        suit = "Club";
    }
    else if (suitNum == 4){
        suit = "Spade";
    }
    else{
        std::cerr << "Invalid Number";
    }
    return suit;
}

Card generateRandomCard(){
    int cardNum;
    int suitNum;
    std::string suit;

    //generate random cardNum
    std::random_device rd1;
    std::mt19937 gen(rd1());
    std::uniform_int_distribution<> distr(1, 13);
    cardNum = distr(gen);

    //generate random suitNum
    std::uniform_int_distribution<> distr(1,4);
    suitNum = distr(gen);

    suit = getSuit(suitNum);

    Card randCard = Card(cardNum,suit);
    return randCard;
};

bool rideTheBus(){
    //Card setup
    Card card1 = generateRandomCard();
    Card card2 = generateRandomCard();
    Card card3 = generateRandomCard();
    Card card4 = generateRandomCard();

    //Round 2 setup
    std::string round2Answer;
    if (card1.getNumber()<card2.getNumber()){
        round2Answer = "Over";
    }
    else if (card1.getNumber()<card2.getNumber()){
        round2Answer = "Under";
    }
    else{
        round2Answer = "F";
    }

    //Round 3 setup
    std::string round3Answer;
    if (card1.getNumber()<card3.getNumber()<card2.getNumber() 
    || card2.getNumber()<card3.getNumber()<card1.getNumber()){
        round3Answer = "Inside";
    }
    else if (card3.getNumber()>card2.getNumber() && card3.getNumber()>card1.getNumber()
    || card3.getNumber()<card2.getNumber() && card3.getNumber()<card1.getNumber()){
        round3Answer = "Outside";
    }
    else{
        round3Answer = "F";
    }

    
    //Round 1
    std::cout << "Red or Black?" <<std::endl;
    std::string round1;
    std::cin >> round1;
    if (round1 != card1.getColor()){
        return false;
    }
    std::cout << "Correct! ";

    //Round 2
    std::cout << "Over or Under?" << std::endl;
    std::string round2;
    std::cin >> round2;
    if (round2 != round2Answer){
        return false;
    }
    std::cout << "Correct! ";

    //Round 3
    std::cout << "Inside or Outside?" << std::endl;
    std::string round3;
    std::cin >> round3;
    if (round3 != round3Answer){
        return false;
    }
    std::cout << "Correct! ";

    //Round 4
    std::cout << "Suit?" << std::endl;
    std::string round4;
    std::cin >> round4;
    if (round4 != card4.getSuit()){
        return false;
    }
    std::cout << "Correct! You may now exit the bus! " << std::endl;
    return true;
}

int main(){
    bool busWon = false;
    while (!busWon){
        busWon = rideTheBus();
        std::cout << "Drink Bitch." << std::endl;
    }
    return 0;
}