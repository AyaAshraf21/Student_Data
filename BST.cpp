#include "BST.h"

BST::BST(vector<Student> currentStudents) {
	root = nullptr;
	for(Student std: currentStudents)
		insertPrivate(root, std);
}

void BST::insertPrivate(Node*& ptr, Student val) {
	if (ptr == nullptr) {
		ptr = new Node(val);
		return;
	}
	else {
		if (val.get_id() <= ptr->key.get_id()) {
			insertPrivate(ptr->left, val);
		}
		else {
			insertPrivate(ptr->right, val);
		}
	}
}

/*void BST::insert(Student newStudent) {
	insertPrivate(root, newStudent);
}


// open & read file
bool BST::check_file(string filename) {
	ifstream File;
	File.open(filename);
	if (!File) {
		cout << "cannot open file , please try again" << endl;
		return false;
	}
	File.close();
	return true;
}


void BST::read_file() {
	ifstream File;
	int num, id;
	string name, dep;
	float gpa;
	File.open("Student_Data.txt");

	if (check_file("Student_Data.txt")) {
		File >> num;
		for (int i = 0; i < num; i++) {
			File >> id;
			getline(File >> ws, name);
			File >> gpa >> dep;
			Student stud(id, name, gpa, dep);
			insert(stud);
		}
		
	}
	File.close();
}
*/

void BST::in_order(Node* ptr) {
	if (ptr == nullptr) {
		return;
	}
	else {
		in_order(ptr->left);
		cout << ptr->key << endl;
		in_order(ptr->right);
	}
}


void BST::add_student(Student newStudent) {
	insertPrivate(root, newStudent);
	cout << "The student is added" << endl;
}

void BST::print_all()
{
	in_order(root);
}
