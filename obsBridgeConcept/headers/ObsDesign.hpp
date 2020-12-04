#pragma once

class Counter;

class Observer {
    public:
        virtual void update(Counter* c) = 0;
};

class Subject {
    public:
       virtual void attach(Observer* o) = 0;
       virtual void detach(Observer* o) = 0;
       virtual void notify() = 0;
};