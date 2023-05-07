#ifndef HEAP_H
#define HEAP_H
#include <bits/stdc++.h>
#include "Student.h"
using namespace std;

class HEAP
{
protected:
    vector<Student> students;
public:
    void insert(Student item);
    void print();
    virtual void heapify() = 0;
    int size(){ return students.size();}
};

class minHEAP : public HEAP
{
    void heapify();
};

class maxHEAP : public HEAP
{
    void heapify();
};

#endif