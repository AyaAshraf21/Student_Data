#ifndef BST_H
#define BST_H
#include <bits/stdc++.h>
#include "Student.h"

struct Node {
	Student key;
	Node* right;
	Node* left;


	Node() {
		right = left = nullptr;
	}

	Node(Student val, Node* r = nullptr, Node* l = nullptr) {
		key = val;
		right = r;
		left = l;
	}
};

class BST
{
private:
	Student stud;
	Node* root;
	Node* prev = nullptr;
	bool dir;

	void insertPrivate(Node*& ptr, Student val);

public:
	BST(vector<Student> currentStudents);
	//void insert(Student newStudent);
	//bool check_file(string filename);
	//void read_file();
	void in_order(Node* ptr);
	void add_student(Student newStudent);
	void remove_student(int id, string name, float gpa, string department);
	void search_student(int id);
	void print_all();
};

#endif