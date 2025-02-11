#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data=x;
        left = right = nullptr;
    }
};

bool inorder(Node* root, int &prev){
    if(!root){
        return true;
    }

    if(!inorder(root->left, prev)){
        return false;
    }

    if(prev >= root->data){
        return false;
    }

    prev = root->data;

    return inorder(root->right, prev);
}

bool isBST(Node* root){
    int prev = INT_MIN;
    return inorder(root, prev);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    if(isBST(root)){
        cout << "True" <<endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}