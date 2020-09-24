//
// Created by Olga on 16/09/2020.
//

#ifndef TTIMER_TIMER_H
#define TTIMER_TIMER_H
/*
 * Класс трекера времени. Я назвала его таймер.
 * Нужен для того чтобы засекать время.
 * */

#include <chrono>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
using namespace std::chrono;

class Timer {
private:
    /* Сразу вопрос к вам - что такое private: и public: */

    /* Начало отсчета */
    time_point<steady_clock> start;
    /* Конец отсчета */
    time_point<steady_clock> end;
    /* Время которое прошло, кстати вопрос - что за тип milliseconds ms */
    milliseconds ms = std::chrono::milliseconds(0);
public:
    Timer();

    /* Начинаем отсчет времени */
    void start_timer();

    /* Закончикли отсчет времени */
    void stop_timer();

    /* Очистить сохраненное время*/
    void clear_timer();

    /* Вывести время которое мы засекли */
    void print_time();

    /* Вернуть время которое мы засекли в заданном формате
     * char fmt = s seconds
     * char fmt = m minutes
     * char fmt = h hours
     * */

    int get_elapsed_time(char fmt);

    /* Вернуть строку вида h:m:s */
    string format_elapsed_time();
};

#endif //TTIMER_TIMER_H
