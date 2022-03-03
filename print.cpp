#include <iostream>
#include <iomanip>

#include "print.h"

void progressBar (int n, int MAX) {
    for (int i=0; i<MAX; i++) {
        if (i<n) 
            std::cout<<"#";
        else 
            std::cout<<"-";
    }
}

void printBeverage (struct BEVERAGE beverage) {
    std::cout.setf(std::ios::fixed);
    std::cout<<"+--------------------+--------------------+--------------------+--------------------+--------------------+\n";

    for (int i=0; i<5; i++)
        std::cout<<"|         "<<beverage.id<<i<<"         ";
    std::cout<<"|\n";
    for (int i=0; i<5; i++) {
        if (beverage.s[i]>0)
            std::cout<<"|"<<std::setw(10)<<beverage.name<<": "<<std::setprecision(2)<<beverage.price<<"$   ";
        else std::cout<<"|     Terminato.     ";
    }
    std::cout<<"|\n";
    for (int i=0; i<5; i++) {
        std::cout<<"|    [";
        progressBar(beverage.s[i], 10);
        std::cout<<"]    ";
    }
    std::cout<<"|\n";
}

void printAllBeverages (struct BEVERAGE* beverage) {
    for (int i=0; i<ROWS; i++)
        printBeverage(beverage[i]);
    std::cout<<"+--------------------+--------------------+--------------------+--------------------+--------------------+\n";
}