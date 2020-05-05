#include <bits/stdc++.h>
#include "BST.h"
#include "avl.h"
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

// int main(int argc, char** argv){
//     AVL *avl = new AVL();
//     BST *bst = new BST();
//     auto start = high_resolution_clock::now();
//     ifstream file("small-file.txt");
//     string linestr;
//     int counter = 20000;
//     while (getline(file, linestr,' ') && counter--){
//         string res = removePunc(linestr);
//         avl->insert(res);
//     }
//     auto end = high_resolution_clock::now();
//     auto duration = duration_cast<seconds>(end - start);
//     avl->inorder();
//     cout<<avl->search("well")<<endl;
//     cout<<avl->search("how")<<endl;
//     cout<<avl->search("steven")<<std::endl;
//     avl->deleteNode("EBook");
//     cout<<"After the deletion the tree is : "<<endl;
//     avl->inorder();
//     cout<<endl;
//     cout<<"------ ------- ------ \n";
//     avl->postorder();
//     cout<<"It took "<<duration.count()<<" seconds to execute "<<endl;
// }


//for testing purposes
int main(int argc, char** argv){
    AVL* avl = new AVL();
    avl->insert("steve");
    avl->insert("bee");
    avl->insert("demer");
    avl->insert("zero");
    avl->insert("animal");
    avl->insert("eagle");
    // avl->deleteNode("bee");
    // avl->deleteNode("steve");
    cout<<avl->search("demer")<<endl;
    avl->inorder();
    cout<<endl;
    avl->preorder();
    return 0;
}