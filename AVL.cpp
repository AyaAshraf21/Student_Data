#include "AVL.h"



AVL::Node* AVL::createNode(Student value){
    AVL::Node* newNode = new Node();
    newNode->key = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

int AVL::height(AVL::Node* myNode){
    if(myNode == nullptr){
        return 0;
    }
    else{
        return myNode->height;
    }
}

int AVL::incrementHeight(AVL::Node* myNode){
    myNode->height = 1+ max(height(myNode->left), height(myNode->right));
}

int AVL::getHeightDifference(AVL::Node *myNode){
    if(myNode == nullptr){
        return 0;
    }
    else{
        return height(myNode->left) -height(myNode->right);
        // this returns the balance factor from left to right
        // 2+ means left skew, -2 means right skew
    }
}


AVL::Node* AVL::leftLeftRotate(AVL::Node* parent){          //  result:         smallChild
    AVL::Node* smallChild;                       //                   /      \
        smallChild = parent->left;             //        bigGrandChild      parent
    AVL::Node* bigGrandChild = smallChild->right;

    parent->left = bigGrandChild;
    smallChild->right = parent;
    // smallChild becomes the "top" one (root/closer to root), replacing parent
    // so first bigGrandChild becomes the smallChild
    // and parent becomes the right of smallChild

    incrementHeight(parent);
    incrementHeight(smallChild);

    return bigGrandChild;

}

AVL::Node* AVL::rightRightRotate(AVL::Node* parent) {
    AVL::Node* bigChild = parent->right;         //         bigChild
    AVL::Node* smallGrandChild = bigChild->left;//          /       \
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

AVL::Node* AVL::leftRightRotate(AVL::Node* parent){
    AVL::Node* smallChild = parent->left;
    parent->left = rightRightRotate(smallChild);
    return leftLeftRotate(parent);
}

AVL::Node* AVL::rightLeftRotate(AVL::Node* parent){
    AVL::Node* bigChild = parent->right;
    parent->right = leftLeftRotate(bigChild);
    return rightRightRotate(parent);
}

AVL::Node* AVL::balanceTree(Node* myNode){
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

AVL::Node* AVL::insertPrivate(AVL::Node *newNode, Student newStudent) {
    if (newNode == nullptr) {
        root = createNode(newStudent);
        return root;
    } else if (newStudent < newNode->key) {
        newNode->left = insertPrivate(newNode->left, newStudent);
        newNode = balanceTree(newNode);
    } else if (newStudent > newNode->key) {
        newNode->right = insertPrivate(newNode->right, newStudent);
        newNode = balanceTree(newNode);
    } return newNode;
}

AVL::Node* AVL::insert(Student newStudent) {
    insertPrivate(root, newStudent);
    cout << "The student is added" << endl;

}

void AVL::printInOrder(AVL::Node* myNode)
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
