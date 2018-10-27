#include <iostream>
#include <string>
#include "SugarReadingList.h"
#include "SugarReading.h"

using namespace std;

int main() {

    float sugarIn = 0;
    int dayIn;

    SugarReadingList list;
    bool inputting = true;
    string q;
    int day = 0;
    int week = 0;

    cout << "\"q\" to quit\n";


    while(inputting) {
        sugarIn = 0;

        cin >> q;

        sugarIn = ::atof(q.c_str());

        if (sugarIn != 0) {
            list.input(SugarReading(sugarIn,day));
        }
        if (q == "D" || q == "d" || q == "day" || q == "Day") {
            cout << "Day: " << day << endl;
            cout << "max: " << list.dayMax(day) << endl;
            cout << "min: " << list.dayMin(day) << endl;
            cout << "sum: " << list.daySum(day) << endl;
            cout << "readings today: " << list.dayCount(day) << endl;
        }
        if (q == "W" || q == "w" || q == "week" || q == "Week") {
            cout << "Week: " << week << endl;
            cout << "max: " << list.weekMax(week) << endl;
            cout << "min: " << list.weekMin(week) << endl;
            cout << "sum: " << list.weekSum(week) << endl;
            cout << "max delta: " << list.maxDelta(week) << endl;
            cout << "readings this week: " << list.weekCount(week) << endl;
        }
        if (q == "N" || q == "n" || q == "next" || q == "Next") {
            cout << "Day " << ++day << endl;
            if (day > 6) {
                week = 1;
            }
        }
        if (q == "q") {
            inputting = false;
        }
    }
    return 0;
}