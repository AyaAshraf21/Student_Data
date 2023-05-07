#include "AVL.h"


Node* AVL::createNode(Student value){
    Node* newNode = new Node();
    newNode->key = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

int AVL::height(Node* myNode){
    if(myNode == nullptr){
        return 0;
    }
    else{
        return myNode->height;
    }
}

int AVL::incrementHeight(Node* myNode){
    myNode->height = 1+ max(height(myNode->left), height(myNode->right));
}

int AVL::getHeightDifference(Node *myNode){
    if(myNode == nullptr){
        return 0;
    }
    else{
        return height(myNode->left) -height(myNode->right);
        // this returns the balance factor from left to right
        // 2+ means left skew, -2 means right skew
    }
}


Node* AVL::leftLeftRotate(Node* parent){          //  result:         smallChild
    Node* smallChild;                       //                   /      \
        smallChild = parent->left;             //        bigGrandChild      parent
    Node* bigGrandChild = smallChild->right;

    parent->left = bigGrandChild;
    smallChild->right = parent;
    // smallChild becomes the "top" one (root/closer to root), replacing parent
    // so first bigGrandChild becomes the smallChild
    // and parent becomes the right of smallChild

    incrementHeight(parent);
    incrementHeight(smallChild);

    return bigGrandChild;

}

Node* AVL::rightRightRotate(Node* parent) {
    Node* bigChild = parent->right;         //         bigChild
    Node* smallGrandChild = bigChild->left;//          /       \
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

Node* AVL::leftRightRotate(Node* parent){
    Node* smallChild = parent->left;
    parent->left = rightRightRotate(smallChild);
    return leftLeftRotate(parent);
}

Node* AVL::rightLeftRotate(Node* parent){
    Node* bigChild = parent->right;
    parent->right = leftLeftRotate(bigChild);
    return rightRightRotate(parent);
}

Node* AVL::balanceTree(Node* myNode){
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

Node* AVL::insertPrivate(Node *newNode, Student newStudent) {
    if (newNode == NULL) {
        return createNode(newStudent);
    } else if (newStudent < newNode->key) {
        newNode->left = insertPrivate(newNode->left, newStudent);
        newNode = balanceTree(newNode);
    } else if (newStudent > newNode->key) {
        newNode->right = insertPrivate(newNode->right, newStudent);
        newNode = balanceTree(newNode);
    } return newNode;
}

Node* AVL::insert(Student newStudent) {
    insertPrivate(root, newStudent);
}

void AVL::printInOrder(Node* node)
{
    if(node != NULL)
    {
        printInOrder(node->left);
        cout << node->key << " ";
        printInOrder(node->right);
    }
}

void AVL::print(){
    int choice;
    cout << "Would you like to print in order? press 1";
    cin >> choice;
    if(choice == 1){
        printInOrder(root);
    }
}
