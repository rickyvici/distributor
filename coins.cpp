#include <iostream>

#include "coins.h"

float balance;

void insertCoins() {
    std::cout<<"Inserire monete (digita 0 per annullare): ";
    //TODO: Verificare che INPUT sia un NUMERO
    float temp;
    std::cin>>temp;
    balance = balance + temp;
}