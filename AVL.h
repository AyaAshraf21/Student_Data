
#pragma once
#include "Student.h"
struct Node{
    Student key;
    Node* left;
    Node* right;
    int height;
};


class AVL
{
private:
    Node* root;
public:
    AVL(){
        root = nullptr;
        //read_file();
    }
    Node* createNode(Student value);
    int height(Node* myNode);
    int incrementHeight(Node* myNode);
    int getHeightDifference(Node *myNode);
    Node* leftLeftRotate(Node* parent);
    Node* rightRightRotate(Node* parent);
    Node* leftRightRotate(Node* parent);
    Node* rightLeftRotate(Node* parent);
    Node* balanceTree(Node* myNode);
    Node* insertPrivate(Node *newNode, Student newStudent);
    Node* insert(Student newStudent);
    void printInOrder(Node*);
    void print();
};

