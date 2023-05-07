#ifndef HEAP_H
#define HEAP_H
#include <bits/stdc++.h>
#include "Student.h"
using namespace std;

class HEAP
{
protected:
    vector<Student> vec;
public:
    void insert(Student item);
    void print();
    virtual void heapify();
    int size(){ return vec.size();}
};

class minHEAP : protected HEAP
{
    void heapify();
};

class maxHEAP : protected HEAP
{
    void heapify();
};

#endif