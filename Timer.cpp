//
// Created by Olga on 16/09/2020.
//

#include "Timer.h"
Timer ::Timer() {}
void Timer::start_timer() {
    start = steady_clock::now();
}

void Timer::stop_timer(){
    end = steady_clock::now();
    ms += duration_cast<milliseconds>(end-start);
}

void Timer::clear_timer(){
    ms = milliseconds(0);
}

void Timer::print_time() {
    cout << ms.count() << "\n";
}

int Timer::get_elapsed_time(char fmt) {
    seconds s = duration_cast<seconds>(ms);
    minutes m = duration_cast<minutes>(ms);
    hours h = duration_cast<hours>(ms);
    if(fmt=='s')
        cout<<s.count()<<" ";
    if(fmt=='m')
        cout<<m.count()<<" ";
    if(fmt=='h')
        cout<<h.count()<<" ";
    return 0;
}

string Timer::format_elapsed_time() {
    string t="";
    seconds s = duration_cast<seconds>(ms);
    minutes m = duration_cast<minutes>(ms);
    hours h = duration_cast<hours>(ms);
    s -= duration_cast<seconds>(m);
    m -= duration_cast<minutes>(h);
    int ss = (int)(s.count());
    int mm = (int)(m.count());
    int hh = (int)(h.count());
    t=(to_string(hh)+':'+to_string(mm)+':'+to_string(ss));
    return "";
}
