//
// Created by owen on 10/24/18.
//

#include <iostream>
#include <list>
#include <cmath>
#include <climits>
#include "SugarReading.h"
#include "SugarReadingList.h"

using namespace std;

SugarReadingList::SugarReadingList() {

}

void SugarReadingList::input(SugarReading reading) {
    if(reading.getSugar() > 0){
        list.push_back(reading);
    }
}

void SugarReadingList::print() {
    std::list<SugarReading>::iterator iter;
    for (iter = list.begin(); iter != list.end(); ++iter) {
        iter->print();
    }
}

void SugarReadingList::sort() {


    int d = 0;

    bool sorted = false;
    while (!sorted) {

        std::list<SugarReading>::iterator iter;
        std::list<SugarReading>::iterator last;

        sorted = true;
        for (iter = list.begin()++; iter != list.end(); ++iter) {
            last = iter;
            last--;
            if(last->getDay() > iter->getDay()) {
                //swap items
                d++;

                float ts = iter->getSugar();
                int td = iter->getDay();

                iter->setValues(last->getSugar(), last->getDay());

                last ->setValues(ts, td);

                sorted = false;
            }
        }
    }
}

float SugarReadingList::daySum(int day) {
    float sum = 0;

    std::list<SugarReading>::iterator iter;
    for (iter = list.begin(); iter != list.end(); ++iter) {
        if (iter->getDay() == day) {
            sum += iter->getSugar();
        }
    }
    return sum;
}

float SugarReadingList::weekSum(int week) {
    float sum = 0;

    std::list<SugarReading>::iterator iter;
    for (iter = list.begin(); iter != list.end(); ++iter) {
        if (week == 0) {
            if (iter->getDay() <= 6 && iter->getDay() >= 0) {
                sum += iter->getSugar();
            }
        }
        if (week == 1) {
            if (iter->getDay() <= 13 && iter->getDay() >= 7) {
                sum += iter->getSugar();
            }
        }

    }
    return sum;
}

int SugarReadingList::dayCount(int day) {
    int c = 0;

    std::list<SugarReading>::iterator iter;
    for (iter = list.begin(); iter != list.end(); ++iter) {
        if (iter->getDay() == day) {
            c++;
        }
    }
    return c;
}

int SugarReadingList::weekCount(int week) {
    int c = 0;

    std::list<SugarReading>::iterator iter;
    for (iter = list.begin(); iter != list.end(); ++iter) {
        if (week == 0) {
            if (iter->getDay() <= 6 && iter->getDay() >= 0) {
                c++;
            }
        }
        if (week == 1) {
            if (iter->getDay() <= 13 && iter->getDay() >= 7) {
                c ++;
            }
        }

    }
    return c;
}

float SugarReadingList::dayMax(int day) {
    int max = 0;

    std::list<SugarReading>::iterator iter;
    for (iter = list.begin(); iter != list.end(); ++iter) {
        if (iter->getDay() == day && iter->getSugar() > max) {
            max = iter->getSugar();
        }
    }
    return max;
}

float SugarReadingList::dayMin(int day) {
    int min = INT_MAX;

    std::list<SugarReading>::iterator iter;
    for (iter = list.begin(); iter != list.end(); ++iter) {
        if (iter->getDay() == day && iter->getSugar() < min) {
            min = iter->getSugar();
        }
    }
    return min;
}

float SugarReadingList::weekMax(int week) {
    int max = 0;

    std::list<SugarReading>::iterator iter;
    for (iter = list.begin(); iter != list.end(); ++iter) {
        if (week == 0) {
            if (iter->getDay() <= 6 && iter->getDay() >= 0 && iter->getSugar() > max) {
                max = iter->getSugar();
            }
        }
        if (week == 1) {
            if (iter->getDay() <= 13 && iter->getDay() >= 7 && iter->getSugar() > max) {
                max = iter->getSugar();
            }
        }
    }
    return max;
}

float SugarReadingList::weekMin(int week) {
    int min = INT_MAX;

    std::list<SugarReading>::iterator iter;
    for (iter = list.begin(); iter != list.end(); ++iter) {
        if (week == 0) {
            if (iter->getDay() <= 6 && iter->getDay() >= 0 && iter->getSugar() < min) {
                min = iter->getSugar();
            }
        }
        if (week == 1) {
            if (iter->getDay() <= 13 && iter->getDay() >= 7 && iter->getSugar() < min) {
                min = iter->getSugar();
            }
        }
    }
    return min;
}

float SugarReadingList::maxDelta(int week) {
    float max = 0;
    float last;
    bool first = true;

    std::list<SugarReading>::iterator iter;
    for (iter = list.begin(); iter != list.end(); ++iter) {
        if (week == 0) {
            if (iter->getDay() <= 6 && iter->getDay() >= 0) {
                if (first) {
                    last = iter->getSugar();
                    first = false;
                } else {
                    if (abs(iter->getSugar() - last) > max) {
                        max = abs(iter->getSugar() - last);
                        last = iter->getSugar();
                    }
                }
            }
        }
        if (week == 1) {
            if (iter->getDay() <= 13 && iter->getDay() >= 7) {
                if (first) {
                    last = iter->getSugar();
                    first = false;
                } else {
                    if (abs(iter->getSugar() - last) > max) {
                        max = abs(iter->getSugar() - last);
                        last = iter->getSugar();
                    }
                }
            }
        }
    }
    return max;
}
