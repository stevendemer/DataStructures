#include "Node.h"


Node::Node(std::string d){
    data = d;
    left = right = nullptr;
    height = 1;
    counter = 0;
}

Node::Node(const Node& n){
    this->left = n.left;
    this->right = n.right;
    this->setData(n.getData());
    height = 1;
    counter = 0;
}

Node::~Node(){
    delete left;
    delete right;
}

std::string Node::getData() const{
    return data;
}

void Node::setData(std::string d){
    data = d;
}



