#pragma once
#include "Node.h"
#include <bits/stdc++.h>

/*In a binary search tree the left subtree's nodes have keys less than the root's 
and the right subtree's nodes have keys greater than that of the root's.
This is the internal implementation of the BST class which ultilizes
the root node so i can use recursion (the root node is not accessible by the user).
I named the data of node key in the function params to avoid confusion

    Author : Steven Demertzis
    Date : Sunday 26 April 2020
    AEM : 3467
*/

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