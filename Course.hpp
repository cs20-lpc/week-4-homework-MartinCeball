#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>

class Course {
private:
    std::string courseName;
    std::string location;

public:
    Course(const std::string& name, const std::string& loc);
    void display() const;
};

#endif // COURSE_HPP

