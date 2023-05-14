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


node* AVL::leftLeftRotate(node* parent){          //  result:   smallChild
    node* smallChild;                                /*         /      \        */
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
    search(id);
    removePrivate(root, id);
    cout << "Student id Deleted" << endl;
    
}

/* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
node *AVL::findSmallestNode(node* myNode)
{
    node* current = myNode;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
// Recursive function to delete a node
// with given key from subtree with
// given root. It returns root of the
// modified subtree.
node* AVL::removePrivate(node* root, int id)
{
     
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;
 
    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if (id < root->key.get_id())
        root->left = removePrivate(root->left, id);
 
    // If the key to be deleted is greater
    // than the root's key, then it lies
    // in right subtree
    else if(id > root->key.get_id())
        root->right = removePrivate(root->right, id);
 
    // if key is same as root's key, then
    // This is the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            node *temp = root->left ? root->left : root->right;
 
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp; // Copy the contents of the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            node* temp = findSmallestNode(root->right);
 
            // Copy the inorder successor's
            // data to this node
            root->key = temp->key;
 
            // Delete the inorder successor
            root->right = removePrivate(root->right, temp->key.get_id());
        }
    }
 
    // If the tree had only one node
    // then return
    if (root == NULL)
        return root;
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    incrementHeight(root);
 
    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getHeightDifference(root);
 
    // If this node becomes unbalanced,
    // then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getHeightDifference(root->left) >= 0)
        return leftLeftRotate(root);
 
    // Left Right Case
    if (balance > 1 && getHeightDifference(root->left) < 0)
    {
        root->left = rightRightRotate(root->left);
        return leftLeftRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 && getHeightDifference(root->right) <= 0)
        return rightRightRotate(root);
 
    // Right Left Case
    if (balance < -1 && getHeightDifference(root->right) > 0)
    {
        root->right = leftLeftRotate(root->right);
        return rightRightRotate(root);
    }
 
    return root;
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