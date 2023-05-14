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


void BST::print_all(vector<Student> students)
{
    in_order(root);
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


