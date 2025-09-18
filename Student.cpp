#include "Student.hpp"
#include <iostream>
#include <iomanip>

Student::Student(int id, const std::string& studentName, double studentGpa)
    : studentId(id), name(studentName), gpa(studentGpa), headCourse(nullptr) {}

Student::~Student() {
    CourseNode* current = headCourse;
    while (current != nullptr) {
        CourseNode* nodeToDelete = current;
        current = current->next;
        delete nodeToDelete;
    }
}

int Student::getId() const {
    return studentId;
}

std::string Student::getName() const {
    return name;
}

void Student::addCourse(const Course& course) {
    CourseNode* newNode = new CourseNode(course);
    if (headCourse == nullptr) {
        headCourse = newNode;
    } else {
        CourseNode* current = headCourse;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void Student::display() const {
    std::cout << studentId << " " << name << " " 
              << std::fixed << std::setprecision(1) << gpa;

    if (headCourse == nullptr) {
        std::cout << " None" << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "Courses: ";
        CourseNode* current = headCourse;
        bool first = true;
        while (current != nullptr) {
            if (!first) {
                std::cout << "         ";
            }
            current->courseData.display();
            std::cout << std::endl;
            current = current->next;
            first = false;
        }
    }
}

