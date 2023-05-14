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
    node* smallChild;                       //                   /      \
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

void AVL::print(){
    printInOrder(root);
}
