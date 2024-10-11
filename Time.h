#ifndef TIME_H
#define TIME_H

#include <string>

namespace Time{

    class Time
    {
    public:
        Time();
        Time(int const h, int const m, int const s);
        Time(std::string const& Time_string);

        std::string to_string(bool us = false) const;
        bool is_am() const;
        int get_hour() const;
        int get_minute() const;
        int get_second() const;
        

        bool operator<(Time const& rhs) const;
        bool operator>(Time const& rhs) const;
        bool operator<=(Time const& rhs) const;
        bool operator>=(Time const& rhs) const;
        bool operator==(Time const& rhs) const;
        bool operator!=(Time const& rhs) const;
        Time& operator++();
        Time operator++(int);
        Time& operator--();
        Time operator--(int);
        Time operator+(int const& i);
        Time operator-(int const& i);
        Time& operator+=(int const& i);
        Time& operator-=(int const& i);

    private:
        void check_time() const;

    private:

        int hour {};
        int minute {};
        int second {};


    };

    std::ostream& operator<<(std::ostream& os, Time const& rhs);
    std::istream& operator>>(std::istream& is, Time & rhs);
    Time operator+(int const& i, Time const& time);

}

#endif