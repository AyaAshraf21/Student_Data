#include "HEAP.h"
#define PARENT (CURRENT - 1) / 2
#define FIRST_CHILD (CURRENT * 2 + 1)

HEAP::HEAP(vector<Student> currentStudents)
{
    cout << "INSIDE CONSTURCTOR" << endl;
    for (Student std: currentStudents)
        insert(std);
}

void HEAP::insert(Student newStudent)
{
    cout << "INSIDE INSERT" << endl;
    students.push_back(newStudent);
    cout << "BEFORE HEAPIFY" << endl;
    heapify();
    cout << "AFTER HEAPIFY" << endl;
}

void HEAP::print()
{
    cout << " Inside PRINT " << endl;
    for (Student student : students)
        cout << student << endl;
}

void maxHEAP::heapify()
{
    int CURRENT = size() - 1;

    cout << "The vector now after adding Student #" << students.size() << endl;
    for (int i = 0; i < students.size(); i++)
            cout << students[i].get_gpa() << endl;

    while ((CURRENT != 0) && (students[CURRENT]).hasLargerGPAthan(students[PARENT]))
    {
        swap(students[CURRENT], students[PARENT]);
        //cout << endl << "Swapping " << students[CURRENT] << " & " << students[PARENT] << endl;
        //cout << CURRENT << " --> " << PARENT << endl;
        CURRENT = PARENT;
    }
}

void minHEAP::heapify()
{
    //still working on it
    int CURRENT = 0;

    while ((CURRENT != -1) && students[CURRENT].hasLargerGPAthan(students[FIRST_CHILD]))
    {
        swap(students[CURRENT], students[FIRST_CHILD]);
        CURRENT = FIRST_CHILD;
    }
}

/*int main()
{
    Student s1(12, "Ramy", 3.1, "DS");
    Student s2(14, "Ufo", 2.9, "IT");
    Student s3(17, "Bora", 3.4, "OR");
    Student s4(14, "Reda", 3.8, "CS");
    Student s5(13, "Ramy", 2.6, "DS");
    Student s6(1, "Ufo", 1.1, "IT");
    Student s7(7, "Bora", 2.3, "OR");
    Student s8(9, "Reda", 3.7, "CS");

    vector<Student> currentStudents;
    currentStudents.push_back(s1);
    currentStudents.push_back(s2);
    currentStudents.push_back(s3);
    currentStudents.push_back(s4);
    currentStudents.push_back(s5);
    currentStudents.push_back(s6);
    currentStudents.push_back(s7);
    currentStudents.push_back(s8);
    maxHEAP myHeap(currentStudents);
    myHeap.print();
}*/