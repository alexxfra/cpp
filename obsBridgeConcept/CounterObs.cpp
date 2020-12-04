#include "headers/CounterObs.hpp"
#include "headers/Counter.hpp"
#include <iostream>

using namespace std;

void CounterObs::displayCount(Counter*c) {
    cout << (*c) << endl;
}

void CounterObs::update(Counter* c) {
    displayCount(c);
}

void OverflowObs::displayCount(Counter*c) {
    cout << "An overflow occured, new value: ";
    CounterObs::displayCount(c);
}

void LimitObs::displayCount(Counter*c) {
    cout << "A limit was reacher at value: ";
    CounterObs::displayCount(c);
}