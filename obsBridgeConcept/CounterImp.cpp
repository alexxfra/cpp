#include "headers/CounterImp.hpp"

CounterImp::CounterImp(int init_, int limit_) {
    if (init_ > limit_)
        counterVal = limit_;
    
    else if (init_ < 0)
        counterVal = 0;
    
    else 
        counterVal = init_;
    
    limit = limit_;
}

bool CounterImp::inc() {
    counterVal++;
    return false;
}

bool CounterImp::dec() {
    counterVal--;
    return false;
}

CounterImp::operator int(){
    return counterVal;
}


LimitCounterImp::LimitCounterImp(int init_, int limit_): CounterImp(init_, limit_){}

bool LimitCounterImp::inc(){
    if (counterVal < limit) {
        counterVal++;
        limitOneshot = true;
        return false;
    }
    else if (limitOneshot) {
        limitOneshot = false;
        return true;
    }
    else return false;
}

bool LimitCounterImp::dec(){
    if (counterVal > 0) {
        counterVal--;
        limitOneshot = true;
        return false;
    }
    else if (limitOneshot) {
        limitOneshot = false;
        return true;
    }
    else return false;
}

OverflowCounterImp::OverflowCounterImp(int init_, int limit_): CounterImp(init_, limit_){}

bool OverflowCounterImp::inc() {
    if (counterVal < limit) {
        counterVal++;
        return false;
    }
    else {
        counterVal = 0;
        return true;
    }
}

bool OverflowCounterImp::dec() {
    if (counterVal > 0) {
        counterVal--;
        return false;
    }
    else {
        counterVal = limit;
        return true;
    }
}
