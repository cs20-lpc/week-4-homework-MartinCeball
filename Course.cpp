#include "Course.hpp"
#include <iostream>

Course::Course(const std::string& name, const std::string& loc)
    : courseName(name), location(loc) {}

void Course::display() const {
    std::cout << courseName << " " << location;
}

