//
// Created by Olga on 16/09/2020.
//

#include "Timer.h"



Timer ::Timer() {}
void Timer::start_timer() {
    time_point<steady_clock> start = steady_clock::now();
};

void Timer::stop_timer() {
    time_point<steady_clock> end = steady_clock::now();
    ms += duration_cast<milliseconds>(end - start);
};

void Timer::clear_timer() {
    ms = milliseconds(0);
};

void Timer::print_time() {
    cout << ms.count() << std::endl;
};

int Timer::get_elapsed_time(char fmt) {
    if (fmt == 'h') {
        hours hour = duration_cast<hours>(ms);
        return hour.count();
    } else if (fmt == 'm') {
        minutes minute = duration_cast<minutes>(ms);
        return minute.count();
    } else {
    seconds second = duration_cast<seconds>(ms);
    return second.count();
    }
};

string Timer::format_elapsed_time() { 
    hours hour = duration_cast<hours>(ms);
    minutes minute = duration_cast<minutes>(ms);
    seconds second = duration_cast<seconds>(ms);
    stringstream stream;
    stream << std::setw(2) << std::setfill('0') << to_string(hour.count()) << ':' 
    << std::setw(2) << std::setfill('0') << to_string(minute.count()) << ':' 
    << std::setw(2) << std::setfill('0') << to_string(second.count());
    string result;
    stream >> result;
    return result;
    };