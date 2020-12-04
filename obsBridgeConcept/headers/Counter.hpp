#pragma once
#include <vector>
#include "CounterImp.hpp"
#include "ObsDesign.hpp"

class Counter: public Subject{
    protected:
        CounterImp *cimp;
        std::vector<Observer*> observers;

    public:
		Counter(){}
        Counter(int init_, int limit_);
        virtual ~Counter();
        virtual void inc();
        virtual void dec();
        virtual operator int();
        void attach(Observer* o) override;
        void detach(Observer* o) override;
        void notify() override;
};

class LimitCounter: public Counter {
   	public:
        LimitCounter(int init_, int limit_);
};


class OverflowCounter: public Counter {
   	public:
        OverflowCounter(int init_, int limit_);
};
