#include "Menu.h"



void Menu::mainMenu() {
	cout << "Hello in Student Data ^_^" << endl << endl;
	cout << "please choose Data Structure according to its number" << endl;
	cout << "1. BST \n2. AVL \n3. Min Heap \n4. Max Heap \n5. Exit Program" << endl << endl;
	cout << "Enter your choice: ";
	cin >> choose;
	if (choose == 1) {
		cout << "Your choice is BST" << endl;
		cout << "please Choose one of the following options according to its number" << endl;
		cout << "1. Add student \n2. Remove student \n3. Search student \n4. Print All(sorted by id) \n5. Return to main menu" << endl;
		cout << "Enter your choice: ";
		cin >> num;
		BST_choice(num);
	}
	else if (choose == 2) {
		cout << "Your choice is AVL" << endl;
		cout << "please Choose one of the following options according to its number" << endl;
		cout << "1. Add student \n2. Remove student \n3. Search student \n4. Print All(sorted by id) \n5. Return to main menu" << endl;
		cout << "\nEnter your choice: ";
		cin >> num;
		AVL_choice(num);
	}
	else if (choose == 3) {
		cout << "Your choice is Min Heap" << endl;
		cout << "please Choose one of the following options according to its number" << endl;
		cout << "1. Add student \n2. Print All(sorted by gpa) \n3. Return to main menu" << endl;
		cout << "\nEnter your choice: ";
		cin >> num;
		min_heap_choice(num);
	}
	else if (choose == 4) {
		cout << "Your choice is Min Heap" << endl;
		cout << "please Choose one of the following options according to its number" << endl;
		cout << "1. Add student \n2. Print All(sorted by gpa) \n3. Return to main menu" << endl;
		cout << "\nEnter your choice: ";
		cin >> num;
		max_heap_choice(num);
	}
	else if (choose == 5) {
		exit(0);
	}
}

Student Menu::getStudentInfo()
{
	int id;
	string name, department;
	float gpa;

	cout << "\nEnter student data ";
	cout << "\n\nID : ";
	cin >> id;
	cin.ignore();
	cout << "Name : ";
	getline(cin , name);
	cout << "GPA : ";
	cin >> gpa;
	cin.ignore();
	cout << "Department : ";
	cin >> department;

	Student inputStudent(id, name, gpa, department);
	return(inputStudent);
}


void Menu::BST_choice(int choice) {
	int id;
	string name, department;
	float gpa;
	if (choice == 1) {
		Student inputStudent = getStudentInfo();
		bst.add_student(inputStudent);
	}
	else if (choice == 2) {

	}
	else if (choice == 3) {

	}
	else if (choice == 4) {

	}
	else if (choice == 5) {
		mainMenu();
	}
}

void Menu::AVL_choice(int choice) {
	if (choice == 1) {

	}
	else if (choice == 2) {

	}
	else if (choice == 3) {

	}
	else if (choice == 4) {

	}
	else if (choice == 5) {
		mainMenu();
	}
}

void Menu::min_heap_choice(int choice) {
	if (choice == 1) {

	}
	else if (choice == 2) {

	}
	else if (choice == 3) {
		mainMenu();
	}

}

void Menu::max_heap_choice(int choice) {
	if (choice == 1) {

	}
	else if (choice == 2) {

	}
	else if (choice == 3) {
		mainMenu();
	}
}