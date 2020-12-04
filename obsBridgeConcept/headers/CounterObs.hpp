#pragma once
#include "ObsDesign.hpp"

class CounterObs: public Observer {
    public:
        CounterObs() = default;
        virtual void displayCount(Counter* c);
        void update(Counter* c);
};

class OverflowObs: public CounterObs {
    public:
        void displayCount(Counter* c);
};

class LimitObs: public CounterObs {
    public:
        void displayCount(Counter* c);
};


