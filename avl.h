#pragma once
#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

//SEARCHING INSERTION AND DELETION/DISPLAY ARE WORKING FINE 

class AVL{
  Node* root;

  Node* insert(Node* root, string key);

  Node* deleteNode(Node* root, string key);

  void inorder(Node* root);

  void postorder(Node* root);

  void preorder(Node* root);

  bool search(Node* root, string key);

  Node* findMin(Node* root);

  Node* findMax(Node* root);

  Node* singleLeftRotate(Node* &root);

  Node* singleRightRotate(Node* &root);

  Node* leftRightRotate(Node* &root);

  Node* rightLeftRotate(Node* &root);
  
  int getBalanceFactor(Node* root);

  int getHeight(Node* root);
public:
  AVL();
  ~AVL();
  void insert(string key);
  void deleteNode(string key);
  bool search(string key);
  void inorder();
  void preorder();
  void postorder();
};
