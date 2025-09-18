#include <iostream>
#include <limits>
#include "LinkedList.hpp"

void displayMenu() {
    std::cout << "\n--- Student Record Management ---" << std::endl;
    std::cout << "1. Insert Student" << std::endl;
    std::cout << "2. Delete Student" << std::endl;
    std::cout << "3. Search Student" << std::endl;
    std::cout << "4. Display All" << std::endl;
    std::cout << "5. Count Students" << std::endl;
    std::cout << "6. Add a course to a student" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Enter choice: ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    LinkedList studentList;
    int choice = 0;

    while (choice != 7) {
        displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            clearInputBuffer();
            choice = 0;
            continue;
        }
        
        clearInputBuffer();

        switch (choice) {
            case 1: {
                int id;
                std::string name;
                double gpa;
                std::cout << "Enter ID: ";
                std::cin >> id;
                std::cout << "Enter Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter GPA: ";
                std::cin >> gpa;

                if (std::cin.fail()) {
                    std::cout << "Invalid GPA. Please enter a valid number." << std::endl;
                    clearInputBuffer();
                } else {
                    studentList.insertStudent(Student(id, name, gpa));
                    std::cout << "Student added." << std::endl;
                }
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter ID to delete: ";
                std::cin >> id;
                if (studentList.deleteStudent(id)) {
                    std::cout << "Deleted student with ID " << id << std::endl;
                } else {
                    std::cout << "Student with ID " << id << " not found." << std::endl;
                }
                break;
            }
            case 3: {
                int id;
                std::cout << "Enter ID to search: ";
                std::cin >> id;
                Student* foundStudent = studentList.searchStudent(id);
                if (foundStudent) {
                    std::cout << "Found: ";
                    foundStudent->display();
                } else {
                    std::cout << "Student with ID " << id << " not found." << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << "\nStudents in List:" << std::endl;
                studentList.displayAll();
                break;
            }
            case 5: {
                std::cout << "Total students: " << studentList.countStudents() << std::endl;
                break;
            }
            case 6: {
                int id;
                std::cout << "Enter ID of the student to add a course to: ";
                std::cin >> id;
                Student* student = studentList.searchStudent(id);
                if (student) {
                    std::string courseName, location;
                    std::cout << "Enter Course Name: ";
                    std::cin.ignore(); 
                    std::getline(std::cin, courseName);
                    std::cout << "Enter location: ";
                    std::getline(std::cin, location);
                    student->addCourse(Course(courseName, location));
                    std::cout << "Course added to student " << id << "." << std::endl;
                } else {
                    std::cout << "Student with ID " << id << " not found." << std::endl;
                }
                break;
            }
            case 7: {
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    }

    return 0;
}

