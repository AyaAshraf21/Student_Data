#include "HEAP.h"
#define FIRST_CHILD (CURRENT * 2 + 1)
#define SECOND_CHILD (CURRENT * 2 + 2)
#define SIZE (students.size())

HEAP::HEAP(vector<Student> currentStudents)
{
    for (Student std: currentStudents)
        insert(std);
}

void HEAP::insert(Student newStudent)
{
    students.push_back(newStudent);
    heapify(students.size() - 1, 0);
}

void HEAP::print()
{
    heapSort();
    for (Student student : students)
        cout << student << endl;
}

void maxHEAP::heapify(int Size, int CURRENT = 0)
{
    int larger = CURRENT;

    if (FIRST_CHILD < Size && students[FIRST_CHILD].hasLargerGPAthan(students[larger]))
        larger = FIRST_CHILD;    
    
    if (SECOND_CHILD < Size && students[SECOND_CHILD].hasLargerGPAthan(students[larger]))
        larger = SECOND_CHILD;    

    if (larger != CURRENT)
    {
        swap(students[CURRENT], students[larger]);
        maxHEAP::heapify(Size, larger);
    }
}

void HEAP::heapSort()
{
    for (int i = SIZE / 2 - 1; i > -1; i--)
        heapify(SIZE, i);
    
    for (int i = SIZE - 1; i >= 0; i--)
    {
        swap(students[0], students[i]);
        heapify(i, 0);
    }
}

void minHEAP::heapify(int Size, int CURRENT = 0)
{
    int smaller = CURRENT;

    if (FIRST_CHILD < Size && students[smaller].hasLargerGPAthan(students[FIRST_CHILD]))
        smaller = FIRST_CHILD;    
    
    if (SECOND_CHILD < Size && students[smaller].hasLargerGPAthan(students[SECOND_CHILD]))
        smaller = SECOND_CHILD;    

    if (smaller != CURRENT)
    {
        swap(students[CURRENT], students[smaller]);
        minHEAP::heapify(Size, smaller);
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
    Student s14(50, "Ada", 2.5, "IS");

    vector<Student> currentStudents;
    currentStudents.push_back(s1);
    currentStudents.push_back(s2);
    currentStudents.push_back(s3);
    currentStudents.push_back(s4);
    currentStudents.push_back(s5);
    currentStudents.push_back(s6);
    currentStudents.push_back(s7);
    currentStudents.push_back(s8);
    minHEAP myHeap(currentStudents);
    currentStudents.push_back(s14);
    myHeap.insert(s14);
    myHeap.print();
}*/