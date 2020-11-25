//
// Created by Olga on 16/09/2020.
//

#include "Timer.h"

Timer ::Timer() {}
void Timer::start_timer() {
    start = steady_clock::now();
};

void Timer::stop_timer(){
    end = steady_clock::now();
    ms = ms + duration_cast<milliseconds>(end - start);
};

void Timer::clear_timer(){
    ms = milliseconds(0);
};
void Timer::print_time() {
    std::cout<<ms.count();
};

int Timer::get_elapsed_time(char fmt) {
    if (fmt == 'h'){
        return duration_cast<hours>(ms).count();
    }
    if (fmt == 'm'){
        return duration_cast<minutes>(ms).count();
    }
    if (fmt == 's'){
        return duration_cast<seconds>(ms).count();
    }
    return 0;};

string Timer::format_elapsed_time() {
    string HH="0",MM="0",SS="0",TIME="";
    hours h = duration_cast<hours>(ms);
    minutes m = duration_cast<minutes>(ms) % 60;
    seconds s = duration_cast<seconds>(ms) % 60;
    if (h.count() < 10)
    {
        HH.append(to_string(h.count()));
        HH.append(":");
    }
    else
    {
       HH = to_string(h.count());
       HH.append(":");
    }
    if (m.count() < 10)
    {
        MM.append(to_string(m.count()));
        MM.append(":");
    }
    else
    {
        MM = to_string(m.count());
        MM.append(":");
    }
    if (s.count() < 10)
    {
        SS.append(to_string(s.count()));
    }
    else
    {
        SS = to_string(s.count());
    }
    TIME.append(HH);
    TIME.append(MM);
    TIME.append(SS);
    return TIME;
};
