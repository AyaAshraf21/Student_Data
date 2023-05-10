#ifndef AVL_H
#define AVL_H

#include "Student.h"
#include <vector>

struct node{
    Student key;
    node* left;
    node* right;
    int height;
};


class AVL
{
private:
    node* root;
public:
    AVL(vector<Student> currentStudents);
    node* createNode(Student value);
    int height(node* myNode);
    int incrementHeight(node* myNode);
    int getHeightDifference(node *myNode);
    node* leftLeftRotate(node* parent);
    node* rightRightRotate(node* parent);
    node* leftRightRotate(node* parent);
    node* rightLeftRotate(node* parent);
    node* balanceTree(node* myNode);
    node* insertPrivate(node *newNode, Student newStudent);
    node* insert(Student newStudent);
    void printInOrder(node*);
    void print();
};

#endif