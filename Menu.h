#pragma once
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
	BST bst;
	AVL avl;

public:
	void mainMenu();
	void BST_choice(int choice);
	void AVL_choice(int choice);
	void min_heap_choice(int choice);
	void max_heap_choice(int choice);
	Student getStudentInfo();
};

