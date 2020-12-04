#include "headers/Counter.hpp"
#include "headers/CounterObs.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void incrementVec(vector<Counter*>& vec, int num);
void useCounter(Counter& ctr, int num);

int main() {
	// Add counters
	vector<Counter*> counters;
	counters.push_back(new OverflowCounter(0,10));
	counters.push_back(new OverflowCounter(0,5));
	counters.push_back(new LimitCounter(0,6));
	counters.push_back(new LimitCounter(0,3));

	// Add observers, Test if detach/attach works with invalid input
	OverflowObs overObs;
	LimitObs limitObs;
	counters[0]->detach(&overObs);
	counters[0]->attach(&overObs);
	counters[1]->attach(&overObs);
	counters[2]->attach(&limitObs);
	counters[3]->attach(&limitObs);
	counters[3]->attach(&limitObs);

	cout << "\nIncrementing by 10: " << endl;
	incrementVec(counters, 11);

	// Detach 2 observers
	counters[1]->detach(&overObs);
	counters[3]->detach(&limitObs);

	cout << "\nDecrementing by 10: " << endl;
	incrementVec(counters, -11);

	// Dealloc
	for (auto p : counters) {
		delete p;
	}

	return 0;
}

void incrementVec(vector<Counter*>& vec, int num) {
	stringstream buff;

	while (num > 0) {
		for (auto& c : vec) {
			c->inc();
			buff << (*c) << " ";
		}
		cout << buff.str() << endl;
		buff.str("");
		buff.clear();
		num--;
	}
	while (num < 0) {
		for (auto& c : vec) {
			c->dec();
			buff << (*c) << " ";
		}
		cout << buff.str() << endl;
		buff.str("");
		buff.clear();
		num++;
	}
	
}

void useCounter(Counter& ctr, int num) {
	cout << ctr << endl;
	while (num > 0) {
		ctr.inc();
		num--;
		cout << ctr << endl;
	}
	while (num < 0) {
		ctr.dec();
		num++;
	}
}
