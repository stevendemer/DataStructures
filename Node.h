#pragma once
#include <string>

class Node{
    std::string data;
public:
    Node* left;
    Node* right;
    int height;
    int counter;
    Node(std::string);
    Node(const Node&);
    ~Node();
    std::string getData() const;
    void setData(std::string);
};