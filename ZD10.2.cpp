#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


struct Student {
    std::string name;
    int grade;
};


bool compareGrades(const Student& a, const Student& b) {
    return a.grade > b.grade; 
}

int main() {

    setlocale(LC_ALL, "Rus");

    int numberOfStudents;
    std::cout << "Сколько студентов вы хотите ввести? ";
    std::cin >> numberOfStudents;

    std::vector<Student> students;
    students.reserve(numberOfStudents);

    
    for (int i = 0; i < numberOfStudents; ++i) {
        Student student;
        std::cout << "Введите имя студента: ";
        std::cin >> student.name;
        std::cout << "Введите оценку студента (от 0 до 100): ";
        std::cin >> student.grade;
        students.push_back(student);
    }

    
    std::sort(students.begin(), students.end(), compareGrades);

    
    std::cout << "\nОтсортированный список студентов:\n";
    for (const Student& student : students) {
        std::cout << student.name << " получил(а) оценку " << student.grade << '\n';
    }

    return 0;
}
