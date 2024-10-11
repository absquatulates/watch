#ifndef WATCH_H
#define WATCH_H
#include "Time.h"

class Watch
{
public:
    Watch();
    Watch(Time::Time & t);

    void display(Time::Time const& time);
    Time::Time getTime(Time::Time const& time);
    void setTime();


private:
    Time::Time time;

};


#endif