#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "BST.h"
#include "AVL.h"
#include "HEAP.h"

using namespace std;

class Menu
{
private:
	int num;
	int choose;
	vector<Student> students;
	//BST bst;
	//AVL avl;
	string dataFile = "Student_Data.txt";

public:
	Menu();
	void mainMenu();
	void BST_choice(int choice);
	void AVL_choice(int choice);
	void min_heap_choice(int choice);
	void max_heap_choice(int choice);
	Student getStudentInfo();
	void readFile();
	void writeFile();
	void vectorPrint(const vector<Student> vec)
	{
		for (Student std: vec)
			cout << std << " ";
	}
	~Menu();
};

#endif