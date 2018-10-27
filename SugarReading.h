//
// Created by owen on 10/25/18.
//

#ifndef PROJECT_1_SUGARREADING_H
#define PROJECT_1_SUGARREADING_H

#include <iostream>
#include <string>
using namespace std;
class SugarReading {
public:
    float sugar = 0;
    int day;
    SugarReading(float s, int d){
        sugar=s;
        day=d;
    }

    float getSugar();

    int getDay();

    string output();

    bool empty();

    void print();

    void setValues(float s, int d);
};

#endif //PROJECT_1_SUGARREADING_H
