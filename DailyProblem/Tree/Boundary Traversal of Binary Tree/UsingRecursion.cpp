#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

bool isLeaf(Node *node){
    return node->left == nullptr && node->right == nullptr;
}

void collectBoundaryLeft(Node* root, vector<int>& res){
    if(root == nullptr || isLeaf(root)){
        return;
    }

    res.push_back(root->data);
    if(root->left){
        collectBoundaryLeft(root->left, res);
    }
    else if(root->right){
        collectBoundaryLeft(root->right, res);
    }
}

void collectLeaves(Node *root, vector<int> &res){
    if(root == nullptr){
        return;
    }

    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }

    collectLeaves(root->left, res);
    collectLeaves(root->right, res);
}

void collectBoundaryRight(Node* root, vector<int>& res){
    if(root == nullptr || isLeaf(root)){
        return;
    }

    if(root->right){
        collectBoundaryRight(root->right, res);
    }
    else if(root->left){
        collectBoundaryRight(root->left, res);
    }
    res.push_back(root->data);
}

vector<int> boundaryTraversal(Node *root){
    vector<int> res;

    if(!root){
        return res;
    }

    if(!isLeaf(root)){
        res.push_back(root->data);
    }

    collectBoundaryLeft(root->left, res);
    collectLeaves(root, res);
    collectBoundaryRight(root->right, res);
    return res;
}

int main(){
    Node  *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right->right = new Node(25);

    vector<int> boundary = boundaryTraversal(root);

    for(int x : boundary){
        cout << x << " ";
    }
    return 0;
}