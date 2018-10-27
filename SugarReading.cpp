//
// Created by owen on 10/24/18.
//
#include <sstream>
#include "SugarReading.h"

using namespace std;

float
SugarReading::getSugar() {
    return sugar;
}

int
SugarReading::getDay() {
    return day;
}

string
SugarReading::output() {

    std::ostringstream ss;
    ss << getSugar() << " " << getDay();
    std::string s(ss.str());
    return s;
}

void
SugarReading::print() {
    cout << "Sugar: " << sugar << "    Day: " << day << endl;
}

bool
SugarReading::empty() {
    return (sugar == 0);
}

void
SugarReading::setValues(float s, int d) {
    sugar = s;
    day = d;
}