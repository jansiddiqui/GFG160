#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    int lCount;
    Node *left, *right;
    Node(int x, int l){
        data = x;
        lCount = l;
        left = right = NULL;
    }
};

int kthSmallestRecur(Node *root, int &k){
    if(root == NULL){
        return -1;
    }

    if(k < root->lCount+1){
        return kthSmallestRecur(root->left, k);
    }

    else if(k == root->lCount+1){
        return root->data;
    }

    else{
        k = k - (root->lCount+1);
        return kthSmallestRecur(root->right, k);
    }
}

int kthSmallest(Node *root, int k){
    return kthSmallestRecur(root, k);
}

int main(){
    Node *root = new Node(20, 5);
    root->left =  new Node(8, 1);
    root->right = new Node(22, 0);
    root->left->left = new Node(4, 0);
    root->left->right = new Node(12, 1);
    root->left->right->left = new Node(10, 0);
    root->left->right->right = new Node(14, 0);

    int k = 3;

    cout<<kthSmallest(root, k)<<endl;

    return 0;
}