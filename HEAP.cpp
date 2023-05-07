#include "HEAP.h"
#define PARENT (CURRENT-1)/2

void HEAP::insert(Student item)
{
    vec.push_back(item);
    heapify();
}

void HEAP::print()
{
    for (Student student : vec)
        cout << student << " ";
    cout << endl;
}

void maxHEAP::heapify()
{
    int CURRENT = size() - 1;

    while ((CURRENT != 0) && (vec[CURRENT]).hasLargerGPAthan(vec[PARENT]))
    {
        swap(vec[CURRENT], vec[PARENT]);
        CURRENT = PARENT;
    }
}

void minHEAP::heapify()
{
    
}