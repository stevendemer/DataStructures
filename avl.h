#pragma once
#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

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

  Node* leftRotation(Node* root);

  Node* rightRotation(Node* root);
  
  int getBalanceFactor(Node* root);

  // int updateHeight(Node* root);

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
