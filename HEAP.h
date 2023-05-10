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
    HEAP(vector<Student> currentStudents);
    void insert(Student newStudent);
    void print();
    virtual void heapify(){};
    int size(){ return students.size();}
};

class minHEAP : public HEAP
{
    public:
    minHEAP(vector<Student> currentStudents) : HEAP(currentStudents){}
    void heapify(int);
};

class maxHEAP : public HEAP
{
    public:
    maxHEAP(vector<Student> currentStudents) : HEAP(currentStudents){}
    void heapify();
};

#endif