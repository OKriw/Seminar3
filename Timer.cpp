//
// Created by Olga on 16/09/2020.
//

#include <chrono>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Timer.h"

using std::chrono::steady_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::minutes;
using std::chrono::hours;
using std::chrono::duration_cast;

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::setw;
using std::setfill;

Timer::Timer() {}
void Timer::start_timer() {
	start = steady_clock::now();
};

void Timer::stop_timer() {
	end = steady_clock::now();
	ms += duration_cast<milliseconds>(end - start);
};

void Timer::clear_timer() {
	ms = milliseconds(0);
};


void Timer::print_time() {
	cout << ms.count() << endl;
};

int Timer::get_elapsed_time(char fmt) {
	switch (fmt) {
	case 's':
		return duration_cast<seconds>(ms).count();
	case 'm':
		return duration_cast<minutes>(ms).count();
	case 'h':
		return duration_cast<hours>(ms).count();
	default:
		return -1;
	}
};

string Timer::format_elapsed_time() {
	string result;
	stringstream str;
	// Each number must be write in 2 digits
	str << setw(2) << setfill('0') << get_elapsed_time('h') << ":";
	str << setw(2) << setfill('0') << get_elapsed_time('m') << ":";
	str << setw(2) << setfill('0') << get_elapsed_time('s') << endl;
	str >> result;
	return result;
};
