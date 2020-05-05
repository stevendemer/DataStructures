#include "avl.h"
using namespace std;


AVL::AVL(){
  root = nullptr;
}

AVL::~AVL(){
  delete root;
}

void AVL::insert(string key){
  root = insert(root, key);
}

void AVL::deleteNode(string key){
  root = deleteNode(root, key);
}

bool AVL::search(string key){
  bool s = search(root, key);
  return s;
}

void AVL::inorder(){
  inorder(root);
}

void AVL::postorder(){
  postorder(root);
}

void AVL::preorder(){
  preorder(root);
}

//ultility function to get the balance factor
// -1<=BF<=1 for the tree to be balanced
int AVL::getBalanceFactor(Node* root){
  if (!root)
    return 0;
  else{
    return getHeight(root->left) - getHeight(root->right);
  }
}

int AVL::getHeight(Node* root){
  if (!root)
    return -1;
  return root->height;
}

//left left case
//O(1) space and time complexity
Node* AVL::singleRightRotate(Node* &root){
  Node* pivot = root->left;
  Node* x = pivot->right;
  //the rotation part
  root->left = x;
  pivot->right = root;
  //update the height 
  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  pivot->height = max(getHeight(pivot->left), getHeight(pivot->right)) + 1;
  //return the new root node
  return pivot;
}

//right right case
//O(1) space and time complexity
Node* AVL::singleLeftRotate(Node* &root){
  Node* pivot = root->right;
  Node* x = pivot->left;
  //the rotation part 
  root->right = x;
  pivot->left = root;
  //update the height 
  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  pivot->height = max(getHeight(pivot->left), getHeight(pivot->right)) + 1;
  //return the new root node
  return pivot;
}

//left right case
Node* AVL::rightLeftRotate(Node* &root){
  root->left = singleLeftRotate(root->left);
  return singleRightRotate(root);
}

//right left case
Node* AVL::leftRightRotate(Node* &root){
  root->right = singleRightRotate(root->right);
  return singleLeftRotate(root);
}

Node* AVL::findMin(Node* root){
  if (!root || !root->left)
    return root;
  return findMin(root->left);
}

Node* AVL::findMax(Node* root){
  if (!root || !root->right)
    return root;
  return findMax(root->right);
}

bool AVL::search(Node* root, string key){
  //base case the tree is empty
  if (!root)
    return false;
  if (root->getData() == key)
    return true;
  else if (root->getData() > key)
    return search(root->left, key);
  else
    return search(root->right, key);
  //the key is not found
  return false;
}

void AVL::postorder(Node* root){
  if (!root)
    return;
  postorder(root->left);
  postorder(root->right);
  cout<<"---> "<<root->getData()<<endl;
}

void AVL::inorder(Node* root){
  if (!root)
    return;
  inorder(root->left);
  cout<<"---> "<<root->getData()<<endl;
  inorder(root->right);
}

void AVL::preorder(Node* root){
  if (!root)
    return;
  cout<<"---> "<<root->getData()<<endl;
  preorder(root->left);
  preorder(root->right);
}

Node* AVL::insert(Node* root, string key){
  //base case the tree is empty
  if (!root)
    return new Node(key);
  if (root->getData() > key)
    root->left = insert(root->left, key);
  else if (root->getData() < key)
    root->right = insert(root->right, key);
    //in case of duplicate values just 
    //increase the counter by 1 and return the 
    //root node
  else{
    root->counter++;
    return root;
 }  
 if (!root)
    return root;
  //update the height
  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;  
  //get the bf and check if the tree is balanced
  //There are 4 cases
  int balance_factor = getBalanceFactor(root);
  //LEFT LEFT Case 
  if (balance_factor > 1 && key < root->left->getData())    
    return singleRightRotate(root);
  //Right Right Case
  if (balance_factor < -1 && key > root->right->getData())
    return singleLeftRotate(root);  
  //Left Right Case
  if (balance_factor > 1 && key > root->left->getData())
      return rightLeftRotate(root);
  //Right Left Case
  if (balance_factor < -1 && key < root->right->getData())
      return leftRightRotate(root);
  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  return root;
}

Node* AVL::deleteNode(Node* root, string key){
  //base case the tree is empty
  if (!root)
    return root;
  //if this is true then the node lies in the left subtree
  if (root->getData() > key)
    root->left = deleteNode(root->left, key);
  //and this in the right subtree
  else if (root->getData() < key)
    root->right = deleteNode(root->right, key);
  //this is the node we are searching for
  else{
    //we check the subtrees
    if (!root->left || !root->right){
      Node* temp = root->left ? root->left : root->right;
      //no child case
      if (!temp){
        temp = root;
        root = nullptr;
      }
      //one child case
      else{
        *root = *temp;
        delete temp;
      }
    }  
    //in case of 2 children then find the inorder successor and 
    //swap its values with the root node and then delete it
    else{
      Node* temp = findMin(root->right);
      //copy its value 
      root->setData(temp->getData());
      root->counter = temp->counter;
      //delete the inorder successor
      root->right = deleteNode(root->right, root->getData());
    }      
  }
  if (!root)
    return root;
  //update the height of the new tree
  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  //check for the balance factor
  int bf = getBalanceFactor(root);
  //in case the tree is unbalanced there are 4 cases
  //left left rotation
  if (bf > 1 && root->left->getData() > key)
      return singleRightRotate(root);
    //right right rotataion
  if (bf < -1 && root->right->getData() < key)
    return singleLeftRotate(root);
  //left right rotation
  if (bf > 1 && root->left->getData() < key)
    return rightLeftRotate(root);
  //right and left rotation
  if (bf < -1 && root->right->getData() > key)
    return leftRightRotate(root);
  return root;
}