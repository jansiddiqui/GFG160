#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

int maxPathSumUtil(Node* root, int& res){
    if(root == nullptr){
        return 0;
    }

    int l = max(0, maxPathSumUtil(root->left, res));
    int r = max(0, maxPathSumUtil(root->right, res));

    res = max(res, l + r + root->data);

    return root->data + max(l, r);

}

int maxPathSum(Node* root){
    int res = root->data;

    maxPathSumUtil(root, res);

    return res;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    cout<<maxPathSum(root);
    return 0;
}