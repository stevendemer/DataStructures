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

// int AVL::updateHeight(Node* root){
//   if (!root)
//     return -1;
//   root->height = max(root->left->height, root->right->height) + 1;
//   return root->height;
// }

/* root
  /    \
  A      pivot
        /
        temp
*/
//O(1) Space complexity
Node* AVL::leftRotation(Node* root){
  Node* pivot = root->right;
  Node* temp = pivot->left;
  //perform rotation
  pivot->left = root;
  root->right = temp;
  //update the heights
  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  pivot->height = max(getHeight(pivot->left), getHeight(pivot->right)) + 1;
  //return the new root;
  return pivot;
}

Node* AVL::rightRotation(Node* root){
  Node* pivot = root->left;
  Node* temp = pivot->right;
  //perform rotation
  pivot->right = root;
  root->left = temp;
  //update the heights
  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  pivot->height = max(getHeight(pivot->left), getHeight(pivot->right)) + 1;
  //return the new root
  return pivot;
}

Node* AVL::findMin(Node* root){
  if (!root || !root->left)
    return root;
  root->left = findMin(root->left);
}

Node* AVL::findMax(Node* root){
  if (!root || !root->right)
    return root;
  root->right = findMax(root->right);
}

bool AVL::search(Node* root, string key){
  //base case the tree is empty
  if (!root)
    return false;
  if (root->getData() == key)
    return true;
  else if (root->getData() > key)
    search(root->left, key);
  else
    search(root->right, key);
  //the key is not found
  return false;
}

void AVL::postorder(Node* root){
  if (!root)
    return;
  postorder(root->left);
  postorder(root->right);
  cout<<root->getData()<<endl;
}

void AVL::inorder(Node* root){
  if (!root)
    return;
  inorder(root->left);
  cout<<root->getData()<<endl;
  inorder(root->right);
}

void AVL::preorder(Node* root){
  if (!root)
    return;
  cout<<root->getData()<<endl;
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
  else{
    root->counter++;
    return root;
 }  
  //update the height
  root->height = max(getHeight(root->left), getHeight(root->right));  
  //get the bf and check if the tree is balanced
  //There are 4 cases
  int balance_factor = getBalanceFactor(root);
  //LEFT LEFT Case 
  if (balance_factor > 1 && key < root->left->getData())    
    return rightRotation(root);
  //Right Right Case
  if (balance_factor < -1 && key > root->right->getData())
    return leftRotation(root);
  //Left Right Case
  if (balance_factor > 1 && key > root->left->getData()){
    root->left = leftRotation(root->left);
    return rightRotation(root);
  }
  //Right Left Case
  if (balance_factor < -1 && key < root->left->getData()){
    root->right = rightRotation(root->right);
    return leftRotation(root);
  }
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
      root->setData(temp->getData());
      //delete the inorder successor
      root->right = deleteNode(root->right, root->getData());
    }      
  }
  //update the height of the new tree
  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  //check for the balance factor
  int bf = getBalanceFactor(root);
  //in case the tree is unbalanced there are 4 cases
  //left left rotation
  if (bf > 1 && root->left->getData() > key)
      return rightRotation(root);
    //right right rotataion
  if (bf < -1 && root->right->getData() < key)
    return leftRotation(root);
  //left right rotation
  if (bf > 1 && root->left->getData() < key){
    root->left = leftRotation(root->left);
    return rightRotation(root);
  }
  //right and left rotation
  if (bf < -1 && root->right->getData() > key){
    root->right = rightRotation(root->right);
    return leftRotation(root);
  }
  return root;
}