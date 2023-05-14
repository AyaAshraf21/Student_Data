#include "Menu.h"

Menu::Menu()
{
	readFile();
}

void Menu::mainMenu() {

    while(choose!=5){
        cout << "\n\n\t\tHello in Student Data ^_^" << endl << endl;
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
            cout << "Your choice is Max Heap" << endl;
            cout << "please Choose one of the following options according to its number" << endl;
            cout << "1. Add student \n2. Print All(sorted by gpa) \n3. Return to main menu" << endl;
            cout << "\nEnter your choice: ";
            cin >> num;
            max_heap_choice(num);
        }
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

void Menu::readFile()
{
	ifstream File;
	int num, id;
	string name, dep;
	float gpa;
	File.open(dataFile);

	if (!File) {
		cout << "Couldn't Open the Data File" << endl;
		return;
	}

	File >> num;
	for (int i = 0; i < num; i++) {
		File >> id;
		getline(File >> ws, name);
		File >> gpa >> dep;
		Student stud(id, name, gpa, dep);
		students.push_back(stud);
	}

	File.close();
}

void Menu::writeFile()
{
	ofstream File;
	File.open(dataFile);
	if(!File)
	{
		cout << "Couldn't Open Data File" << endl;
		return;
	}

	File << students.size() << endl;

	for (Student std: students)
	{
		File << std.get_id() << endl;
		File << std.get_name() << endl;
		File << std.get_gpa() << endl;
		File << std.get_department() << endl;
	}

	File.close();
}


void Menu::BST_choice(int choice) {
	BST bst(students);
	if (choice == 1) {
		Student newStudent = getStudentInfo();
		students.push_back(newStudent);
		bst.add_student(newStudent);
	}
	else if (choice == 2) {
        int ID;
        cout << "Enter the ID: ";
        cin >> ID;
		cout << endl;
        bst.remove_student(ID,students);
    }
	else if (choice == 3) {
		int ID;
		cout << "Enter the ID: ";
		cin >> ID;
		cout << endl;
		bst.search_student(ID);
	}
	else if (choice == 4) {
		bst.print_all(students);
	}
	else if (choice == 5) {
		mainMenu();
	}
}

void Menu::AVL_choice(int choice) {
    AVL avl(students);
	if (choice == 1) {
        Student newStudent = getStudentInfo();
        students.push_back(newStudent);
        avl.insert(newStudent);
    }
	else if (choice == 2) {

	}
	else if (choice == 3) {

	}
	else if (choice == 4) {
        avl.print();
	}
	else if (choice == 5) {
		mainMenu();
	}
}

void Menu::min_heap_choice(int choice) {
	minHEAP minHeap(students);
	if (choice == 1) {
		Student newStudent = getStudentInfo();
		students.push_back(newStudent);
		minHeap.insert(newStudent);
	}
	else if (choice == 2) {
		minHeap.print();
	}
	else if (choice == 3) {
		mainMenu();
	}

}

void Menu::max_heap_choice(int choice) {
	maxHEAP maxHeap(students);
	if (choice == 1) {
		Student newStudent = getStudentInfo();
		students.push_back(newStudent);
		maxHeap.insert(newStudent);
	}
	else if (choice == 2) {
		maxHeap.print();
	}
	else if (choice == 3) {
		mainMenu();
	}
}

Menu::~Menu()
{
	writeFile();
}
