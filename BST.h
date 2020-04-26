#pragma once
#include "Node.h"
#include <bits/stdc++.h>


class BST{
    Node* root;
    Node* insert(Node*, std::string);
    Node* deleteNode(Node*, std::string);
    bool search(Node*, std::string);
    void inorder(Node*);
    void preorder(Node*);
    void postorder(Node*);
    Node* findMin(Node*);
    Node* findMax(Node*);
public:
    BST();
    BST(const BST&);
    ~BST();
    void insert(std::string);
    bool search(std::string);
    void deleteNode(std::string);
    void inorder();
    void postorder();
    void preorder();
};