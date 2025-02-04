#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int diameterRecur(Node* root, int &res){
    if(root == nullptr){
        return 0;
    }

    int lHeight = diameterRecur(root->left, res);
    int rHeight = diameterRecur(root->right, res);

    res = max(res, lHeight+rHeight);

    return 1 + max(lHeight, rHeight);
}

int diameter(Node* root){
    int res = 0;
    diameterRecur(root, res);
    return res;
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(9);

    cout << diameter(root) << endl;

    return 0;
}