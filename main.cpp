#include <bits/stdc++.h>
#include "BST.h"
// #include "avl.h"
using namespace std;
using namespace std::chrono;



//ultility function to remove puncuation marks and return the new string
string removePunc(string& str){
    if (str.empty())
        return str;
    string result = "";
    for (auto& x: str){
        if (!ispunct(x))
            result += x;
    }
    return result;
}

int main(int argc, char** argv){
    // AVL *avl = new AVL();
    BST *bst = new BST();
    auto start = high_resolution_clock::now();
    ifstream file("small-file.txt");
    string linestr;
    int counter = 5;
    while (getline(file, linestr,' ') && counter--){
        string res = removePunc(linestr);
        bst->insert(res);
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    bst->inorder();
    cout<<bst->search("well")<<endl;
    cout<<bst->search("how")<<endl;
    cout<<bst->search("steven")<<std::endl;
    bst->deleteNode("EBook");
    cout<<"After the deletion the tree is : "<<endl;
    bst->inorder();
    cout<<endl;
    cout<<"------ ------- ------ \n";
    bst->postorder();
    cout<<"It took "<<duration.count()<<" seconds to execute "<<endl;
}


