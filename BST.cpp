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

void BST::removePrivate(Node* node, int id) {
    if (node == nullptr) {
        return;
    }
    else if (id < node->key.get_id()) {
        removePrivate(node->left, id);
    }
    else if (id > node->key.get_id()) {
        removePrivate(node->right, id);
    }
    else {
        // Case 1: Node has no children
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
            // Case 2: Node has one child
        else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
            // Case 3: Node has two children
        else {
            Node* successor = node->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            } // find minimum
            node->key = successor->key;
            removePrivate(node->right, successor->key.get_id());
        }
    }
}


void BST::remove_student(int id, vector<Student>& currentStudents){
    bool found = false;
    for(auto it = currentStudents.begin(); it != currentStudents.end(); ++it){
        if(it->get_id() == id){
            cout << "Student found" << endl;
            cout << *it << endl;
            found = true;
            removePrivate(root, it->get_id());
            currentStudents.erase(it);
            cout << "Student is deleted" << endl;
            break;
        }
    }
    if(!found){
        cout << "Student not found." << endl;
        return;
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

void printDepartment(vector<Student> students)
{
    int CS_count = 0, IT_count = 0, DS_count = 0, AI_count = 0, IS_count = 0;
    for(Student student: students){
        string dep = student.get_department();
        transform(dep.begin(), dep.end(), dep.begin(), ::toupper);
        if(dep == "CS"){
            CS_count++;
        }
        else if(dep == "IT"){
            IT_count++;
        }
        else if(dep == "DS"){
            DS_count++;
        }
        else if(dep == "AI"){
            AI_count++;
        }
        else if(dep == "IS"){
            IS_count++;
        }
    }
    cout << "Department Counts:" << endl;
    cout << "CS: " << CS_count << endl;
    cout << "IT: " << IT_count << endl;
    cout << "DS: " << DS_count << endl;
    cout << "AI: " << AI_count << endl;
    cout << "IS: " << IS_count << endl;
}

void BST::print_all(vector<Student> students)
{
    in_order(root);
    printDepartment(students);
}


void BST::search_student(int id)
{
    Node *ptr = root;

    while (ptr != nullptr)
    {
        if (ptr ->key.get_id() == id)
        {
            cout << "Student is found." << endl;
            cout << ptr->key << endl;
            return;
        }

        else if (ptr->key.get_id() > id)
            ptr = ptr->left;
        
        else
            ptr = ptr->right;

    }

    cout << "Student with ID# " << id << " not found." << endl;
    
}


