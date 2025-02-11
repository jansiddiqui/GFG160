#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left=right=nullptr;
    }
};

bool isBSTUtil(Node* node, int min, int max){
    if(node==nullptr){
        return true;
    }

    if(node->data < min || node->data > max){
        return false;
    }

    return isBSTUtil(node->left, min, node->data-1) && isBSTUtil(node->right, node->data+1, max);

}
bool isBST(Node* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    if(isBST(root)){
        cout << " TRUE"<<endl;
    }else{
        cout<<"FALSE"<<endl;
    }
    return 0;
}