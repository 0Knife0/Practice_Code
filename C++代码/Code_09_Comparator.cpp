// basic_calss_01 Comparator.java
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    int id;
    int age;
};

bool IdAscendingComparator(const Student &o1, const Student &o2) {
    return o1.id < o2.id;
}

bool IdDescendingComparator(const Student &o1, const Student &o2) {
    return o2.id < o1.id;
}

bool AgeAscendingComparator(const Student &o1, const Student &o2) {
    return o1.age < o2.age;
}

bool AgeDescendingComparator(const Student &o1, const Student &o2) {
    return o2.age < o1.age;
}

void printStudent(vector<Student> students) {
    for (auto student : students)
        cout << "Name : " << student.name << ", Id : " << student.id
             << ", Age : " << student.age << endl;
    cout << "===========================" << endl;
}

int main() {
    Student student1 = {"A", 1, 23};
    Student student2 = {"B", 2, 21};
    Student student3 = {"C", 3, 22};
    vector<Student> students = {student1, student2, student3};
    printStudent(students);

    sort(students.begin(), students.end(), IdAscendingComparator);
    printStudent(students);

    sort(students.begin(), students.end(), IdDescendingComparator);
    printStudent(students);

    sort(students.begin(), students.end(), AgeAscendingComparator);
    printStudent(students);

    sort(students.begin(), students.end(), AgeDescendingComparator);
    printStudent(students);
}