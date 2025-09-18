#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Student.hpp"

class LinkedList {
private:
    struct Node {
        Student studentData;
        Node* next;
        
        Node(const Student& student) : studentData(student), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList();
    ~LinkedList();
    void insertStudent(const Student& student);
    bool deleteStudent(int id);
    Student* searchStudent(int id);
    void displayAll() const;
    int countStudents() const;
};

#endif // LINKEDLIST_HPP


