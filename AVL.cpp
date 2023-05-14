#include "AVL.h"

AVL::AVL(vector<Student> currentStudents)
{
    root = nullptr;
    for (Student student: currentStudents) 
        insertPrivate(root, student);
}

node* AVL::createNode(Student value){
    node* newNode = new node();
    newNode->key = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    if(root==nullptr){
        root = newNode;
    }
    return newNode;
}

int AVL::height(node* myNode){
    if(myNode == nullptr){
        return 0;
    }
    else{
        return myNode->height;
    }
}

int AVL::incrementHeight(node* myNode){
    myNode->height = 1+ max(height(myNode->left), height(myNode->right));
    return myNode->height;
}

int AVL::getHeightDifference(node *myNode){
    if(myNode == nullptr){
        return 0;
    }
    else{
        return height(myNode->left) -height(myNode->right);
        // this returns the balance factor from left to right
        // 2+ means left skew, -2 means right skew
    }
}


node* AVL::leftLeftRotate(node* parent){          //  result:         smallChild
    node* smallChild;                       //                   /      /
    smallChild = parent->left;             //        bigGrandChild      parent
    node* bigGrandChild = smallChild->right;

    parent->left = bigGrandChild;
    smallChild->right = parent;
    // smallChild becomes the "top" one (root/closer to root), replacing parent
    // so first bigGrandChild becomes the smallChild
    // and parent becomes the right of smallChild

    incrementHeight(parent);
    incrementHeight(smallChild);

    return bigGrandChild;

}

node* AVL::rightRightRotate(node* parent) {
    node* bigChild = parent->right;         //         bigChild
    node* smallGrandChild = bigChild->left;//          /       \
                                              //       parent   smallGrandChild
    parent->right = smallGrandChild;
    bigChild->left = parent;
    // bigChild becomes the "top" one (root/closer to root), replacing parent
    // so first smallGrandChild becomes the bigChild
    // and parent becomes the left of bigChild

    incrementHeight(parent);
    incrementHeight(bigChild);

    return bigChild;
}

node* AVL::leftRightRotate(node* parent){
    node* smallChild = parent->left;
    parent->left = rightRightRotate(smallChild);
    return leftLeftRotate(parent);
}
node* AVL::rightLeftRotate(node* parent){
    node* bigChild = parent->right;
    parent->right = leftLeftRotate(bigChild);
    return rightRightRotate(parent);
}

node* AVL::balanceTree(node* myNode){
    int balanceFactor = getHeightDifference(myNode);
    if (balanceFactor > 1) {
        if (getHeightDifference(myNode->left) > 0)
            myNode = leftLeftRotate(myNode);
        else
            myNode = leftRightRotate(myNode);
    } else if (balanceFactor < -1) {
        if (getHeightDifference(myNode->right) > 0)
            myNode = rightLeftRotate(myNode);
        else
            myNode = rightRightRotate(myNode);
    }
    return myNode;

}

node* AVL::insertPrivate(node *newNode, Student newStudent) {
    if (newNode == nullptr) {
        return createNode(newStudent);
    } else if (newStudent < newNode->key) {
        newNode->left = insertPrivate(newNode->left, newStudent);
        newNode = balanceTree(newNode);
    } else if (newStudent > newNode->key) {
        newNode->right = insertPrivate(newNode->right, newStudent);
        newNode = balanceTree(newNode);
    } return newNode;
}

void AVL::insert(Student newStudent) {
    insertPrivate(root, newStudent);
    cout << "The student is added" << endl;
}

void AVL::remove(int id)
{
    //search(id);
    removePrivate(root, id);
    cout << "Student id Deleted" << endl;
    
}

void AVL::removePrivate(node *myNode, int id) {
    if (myNode == nullptr) {
        return;
    }
    if (id < myNode->key.get_id()) {
        removePrivate(myNode->left, id);
    } else if (id > myNode->key.get_id()) {
        removePrivate(myNode->right, id);
    } else { // id == myNode->key.get_id()
        if (myNode->left == nullptr && myNode->right == nullptr) {
            // no child
            delete myNode;
            myNode = nullptr;
        } else if (myNode->left == nullptr) {
            // one child (right)
            node *temp = myNode;
            myNode = myNode->right;
            temp->right = nullptr; // update parent pointer
            delete temp;
        } else if (myNode->right == nullptr) {
            // one child (left)
            node *temp = myNode;
            myNode = myNode->left;
            temp->left = nullptr; // update parent pointer
            delete temp;
        } else {
            // two children
            node *minRight = findMinNode(myNode->right);
            myNode->key = minRight->key;
            removePrivate(myNode->right, minRight->key.get_id());
        }
    
        if (myNode != nullptr) {
            incrementHeight(myNode);
            myNode = balanceTree(myNode);
        }
    }

}

node *AVL::findMinNode(node *myNode)
{
    if (myNode == nullptr || myNode->left == nullptr)
        return myNode;

    return (findMinNode(myNode->left));
}


void AVL::printInOrder(node* myNode)
{
    if(myNode == nullptr)
    {
        return;
    }

    else {
        printInOrder(myNode->left);
        cout << myNode->key <<endl;
        printInOrder(myNode->right);
    }
}

void AVL::search(int id)
{
    node* current = root;
    while (current != nullptr) {
        if (id == current->key.get_id()) {
            cout << "Student is found." << endl;
            cout << current->key << endl;
            return ;
        }
        else if (id < current->key.get_id()) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    cout << "Student with ID# " << id << " not found." << endl;
}

void AVL::print(){
    printInOrder(root);
}

int main()
{
    Student s1(12, "Ramy", 3.1, "DS");
    Student s2(14, "Ufo", 2.9, "IT");
    Student s3(17, "Bora", 3.4, "OR");
    Student s4(18, "Reda", 3.8, "CS");
    Student s5(13, "Gamal", 2.6, "DS");
    Student s6(1, "LA", 1.1, "IT");
    Student s7(7, "BlaBla", 2.3, "OR");
    Student s8(9, "Rengar", 3.7, "CS");
    Student s14(50, "Ada", 2.5, "IS");

    vector<Student> currentStudents;
    currentStudents.push_back(s1);
    currentStudents.push_back(s2);
    currentStudents.push_back(s3);
    currentStudents.push_back(s4);
    currentStudents.push_back(s5);
    currentStudents.push_back(s6);
    currentStudents.push_back(s7);
    currentStudents.push_back(s8);
    AVL myAVL(currentStudents);
    currentStudents.push_back(s14);
    cout << "Adding Ada: " << endl;
    myAVL.insert(s14);
    myAVL.print();
    cout << "Search for Ada: " << endl;
    myAVL.search(50);
    cout << "Removing Ada: " << endl;
    myAVL.remove(50);
    myAVL.print();
    cout << "All Right" << endl;
}
