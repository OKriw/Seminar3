//
// Created by Olga on 16/09/2020.
//

#include "Timer.h"

Timer ::Timer() {}
void Timer::start_timer() {
    start = steady_clock::now();
};

void Timer::set_time(int millisec) {
    ms = milliseconds(millisec);
    start = end = steady_clock::now();
}

void Timer::stop_timer(){
    end = steady_clock::now();
    ms += duration_cast<milliseconds>(end - start);
};

void Timer::clear_timer(){
    ms = milliseconds(0);
};

void Timer::print_time() {
    std::cout << ms.count() << endl;
};

int Timer::get_elapsed_time(char fmt) {
    if (fmt == 'h') {
        auto hour = duration_cast<hours>(ms);
        return hour.count();
    }
    if (fmt == 'm') {
        auto minute = duration_cast<minutes>(ms);
        return minute.count();
    }
    auto second = duration_cast<seconds>(ms);
    return second.count();
};

string Timer::format_elapsed_time() {
    auto hour = duration_cast<hours>(ms);
    auto minute = duration_cast<minutes>(ms) % 60;
    auto second = duration_cast<seconds>(ms) % 60;
    stringstream stream;
    stream << setw(2) << setfill('0') << to_string(hour.count()) << ':' << setw(2) << setfill('0')
           << to_string(minute.count()) << ':' << setw(2) << setfill('0') << to_string(second.count());
    string result;
    stream >> result;
    return result;
};

