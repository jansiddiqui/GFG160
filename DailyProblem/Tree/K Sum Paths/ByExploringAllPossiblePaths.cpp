#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int value){
        data = value;
        left = right = nullptr;
    }
};

int countPathsFromNode(Node* node, int k, int currentSum){
    if(node == nullptr){
        return 0;
    }

    int pathCount = 0;
    currentSum += node->data;

    if(currentSum == k){
        pathCount++;
    }

    pathCount += countPathsFromNode(node->left, k, currentSum);
    pathCount += countPathsFromNode(node->right, k, currentSum);

    return pathCount;
}

int countAllPaths(Node* root, int k){
    if(root == nullptr){
        return 0;
    }

    int res = countPathsFromNode(root, k, 0);

    res += countAllPaths(root->left, k);
    res += countAllPaths(root->right, k);
    return res;
}


int main(){
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->right = new Node(2);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(-2);
    root->left->right->right = new Node(1);

    int k = 7;

    cout<<countAllPaths(root, k) << endl;

    return 0;
}