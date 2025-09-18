#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include "Course.hpp"

class Student {
private:
    int studentId;
    std::string name;
    double gpa;

    struct CourseNode {
        Course courseData;
        CourseNode* next;

        CourseNode(const Course& course) : courseData(course), next(nullptr) {}
    };

    CourseNode* headCourse;

public:
    Student(int id, const std::string& studentName, double studentGpa);
    ~Student();
    int getId() const;
    std::string getName() const;
    void addCourse(const Course& course);
    void display() const;
};

#endif // STUDENT_HPP

