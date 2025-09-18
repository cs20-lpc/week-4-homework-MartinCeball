#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nodeToDelete = current;
        current = current->next;
        delete nodeToDelete;
    }
}

void LinkedList::insertStudent(const Student& student) {
    Node* newNode = new Node(student);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

bool LinkedList::deleteStudent(int id) {
    if (head == nullptr) return false;

    if (head->studentData.getId() == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->studentData.getId() != id) {
        current = current->next;
    }

    if (current->next == nullptr) {
        return false;
    }

    Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    delete nodeToDelete;
    return true;
}

Student* LinkedList::searchStudent(int id) {
    Node* current = head;
    while (current != nullptr) {
        if (current->studentData.getId() == id) {
            return &(current->studentData);
        }
        current = current->next;
    }
    return nullptr;
}

void LinkedList::displayAll() const {
    if (head == nullptr) {
        std::cout << "The list is empty." << std::endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        current->studentData.display();
        current = current->next;
    }
}

int LinkedList::countStudents() const {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
