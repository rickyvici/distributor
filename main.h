#ifndef MAIN_H_
#define MAIN_H_
#include <string>
#include <cstring>

#define BUFFERDIM 64
#define ROWS 9

struct BEVERAGE {
    int id;
    std::string name;
    int s[5];
    float price;
};

std::string beverageToString(struct BEVERAGE beverage);

#endif