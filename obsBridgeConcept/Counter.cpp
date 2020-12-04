#include "headers/Counter.hpp"
#include <algorithm>
#include <iostream>

Counter::Counter(int init_, int limit_): cimp(new CounterImp(init_, limit_)){}

Counter::~Counter() {
	delete cimp;
}

void Counter::inc() {
	if(cimp->inc())
		notify();
}

void Counter::dec() {
	if(cimp->dec())
		notify();
}

Counter::operator int() {
    return *cimp;
}

void Counter::attach(Observer* o) {
	if (std::find(observers.begin(), observers.end(), o) != observers.end()) {
		std::cout << "This observer is already watching this subject." << std::endl;
	}
	else {
		observers.push_back(o);
	}
}

void Counter::detach(Observer* o) {
	if (std::find(observers.begin(), observers.end(), o) == observers.end()) {
		std::cout << "This observer is not watching this subject." << std::endl;
	}
	else {
		observers.erase(remove(observers.begin(), observers.end(), o));
	}
}

void Counter::notify(){
	for (auto& o : observers) {
		o->update(this);
	}
}


LimitCounter::LimitCounter(int init_, int limit_){
	cimp = new LimitCounterImp(init_, limit_);
}

OverflowCounter::OverflowCounter(int init_, int limit_){
	cimp = new OverflowCounterImp(init_, limit_);
}

