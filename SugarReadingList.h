//
// Created by owen on 10/25/18.
//

#ifndef PROJECT_1_SUGARREADINGLIST_H
#define PROJECT_1_SUGARREADINGLIST_H

#include "SugarReading.h"
#include <string>
#include <list>



class SugarReadingList {
private:
    std::list<SugarReading> list;
public:
    SugarReadingList();

    void input(SugarReading reading);

    void print();

    void sort();

    float daySum(int day);

    int dayCount(int day);

    float weekSum(int week);

    int weekCount(int week);

    float dayMin(int day);

    float dayMax(int day);

    float weekMin(int week);

    float weekMax(int week);

    float maxDelta(int week);
};

#endif //PROJECT_1_SUGARREADINGLIST_H
