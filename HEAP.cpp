#include "HEAP.h"
#define PARENT (CURRENT-1)/2

void HEAP::insert(Student item)
{
    students.push_back(item);
    heapify();
}

void HEAP::print()
{
    for (Student student : students)
        cout << student << " ";
    cout << endl;
}

void maxHEAP::heapify()
{
    int CURRENT = size() - 1;

    while ((CURRENT != 0) && (students[CURRENT]).hasLargerGPAthan(students[PARENT]))
    {
        swap(students[CURRENT], students[PARENT]);
        CURRENT = PARENT;
    }
}

void minHEAP::heapify()
{
    
}