#pragma once

class CounterImp{
    protected:
        int counterVal;
        int limit;

    public:
        CounterImp(int init_, int limit_);
        virtual ~CounterImp() {};
        virtual bool inc();
        virtual bool dec();
        operator int();

};

class LimitCounterImp: public CounterImp{
    private:
        bool limitOneshot = true;
    public:
        LimitCounterImp(int init_, int limit_);
        bool inc() override;
        bool dec() override;
};


class OverflowCounterImp: public CounterImp{
    public:
        OverflowCounterImp(int init_, int limit_);
        bool inc() override;
        bool dec() override;
};
