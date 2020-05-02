#include "BST.h"

Node* BST::insert(Node* root, std::string key){
    //base case the tree is empty so we create the root node and return it
    if (!root)
        return new Node(key);
    //in case the key is less than the root's data then we insert it 
    //to the left subtree
    if (root->getData() > key)
        root->left = insert(root->left, key);
    //else if the key is greater than the root's data then we insert it 
    //to the right subtree
    else if (root->getData() < key)
        root->right = insert(root->right, key);
    //in case of duplicates just increase the counter by 1 and exit
    else{
        root->counter++;
        return root;
    }
    //return the root node after insertion
    return root;
}

//ultility function that uses recursion to find the min value of a tree
Node* BST::findMin(Node* root){
    //base case 
    if (!root || !root->left)
        return root;
    root->left = findMin(root->left);
}

//ultility function that uses recursion to find the max value of a tree
Node* BST::findMax(Node* root){
    if (!root || !root->right)
        return root;
    root->right = findMax(root->right);
}

//inorder (left -> root -> right)
void BST::inorder(Node* root){
    //base case the tree is empty 
    if (!root)
        return;
    inorder(root->left);
    std::cout<<root->getData()<<std::endl;
    inorder(root->right);
}

//postorder(left->right->root)
void BST::postorder(Node* root){
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->getData()<<std::endl;
}

//preorder(root->left->right);
void BST::preorder(Node* root){
    if (!root)
        return;
    std::cout<<root->getData()<<std::endl;
    preorder(root->left);
    preorder(root->right);
}

bool BST::search(Node* root, std::string key){
    if (!root)
        return false;
    if (root->getData() == key)
        return true;
    if (root->getData() > key)
        return search(root->left, key);
    else
        return search(root->right, key);
    //in case the key is not found in the tree
    return false;
}
Node* BST::deleteNode(Node* root, std::string key){
    //base case the tree node is empty 
    if (!root)
        return root;
    if (root->getData() > key)
        root->left = deleteNode(root->left, key);
    else if (root->getData() < key)
        root->right = deleteNode(root->right, key);
    else{
        //in case the node to be deleted has 1 child then we just 
        //delete it
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        else{
            //in case the node has 1 children the we just find the
            //inorder successor(min value of the right subtree) and we swap the key values with the root node
            //and we delete it 
            Node* inorder_succ = findMin(root->right);
            root->setData(inorder_succ->getData());
            root->right = deleteNode(root->right, root->getData());
        }
    }
    return root;
}


//Implementing the public functions that the user is going
//to interact with 

//constructor
BST::BST(){
    root = nullptr;
}

BST::~BST(){
    delete root;
}

BST::BST(const BST& b){
    this->root = b.root;
}

void BST::insert(std::string key){
    root = insert(root, key);
}

void BST::deleteNode(std::string key){
    root = deleteNode(root, key);
}

bool BST::search(std::string key){
    bool t = search(root, key);
    if (t)
        std::cout<<"The key exists in the tree "<<std::endl;
    else
        std::cout<<"The key does not exist in the tree "<<std::endl;
    return t;
}

void BST::inorder(){
    inorder(root);
}

void BST::postorder(){
    postorder(root);
}

void BST::preorder(){
    preorder(root);
}