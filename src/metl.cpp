#define METLDEBUG
#include "metl.h"
#include <iostream>

metl::METL::METL(std::string clock_name) : name(clock_name), stopped(false),
    started(false) {}

metl::METL::~METL() {
    if (!this->stopped) this->stop();
}

metl::METL& metl::METL::start() {
    this->t_start = std::chrono::high_resolution_clock::now();
    this->started = true;

    return *this;
}

void metl::METL::stop() {
    this->t_end = std::chrono::high_resolution_clock::now();
    this->stopped = true;
    this->log_terminal();
}

void metl::METL::log_terminal() {
    std::chrono::duration<double, std::milli> dur = this->t_end - this->t_start;
    std::cout << "Clock \"" << this->name << "\" execution time:"
              << dur.count() << " ms." << std::endl;
}

// static std::list<metl::METL> metl::GlobalControl::clock = {};