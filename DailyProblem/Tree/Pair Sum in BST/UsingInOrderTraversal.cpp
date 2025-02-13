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

void inorderTraversal(Node* root, vector<int>& inorder){
    if(root == NULL){
        return;
    }

    inorderTraversal(root->left, inorder);

    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

bool findTarget(Node* root, int target){
    vector<int> inorder;
    inorderTraversal(root, inorder);

    int left = 0, right = inorder.size() - 1;

    while(left < right){
        int currSum = inorder[left] + inorder[right];
        if(currSum == target){
            return true;
        }
        if(currSum < target){
            left++;
        }
        else{
            right--;
        }
    }
    return false;
}

int main(){
    Node *root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    int target = 35;

    cout << (findTarget(root, target) ? "True" : "False");
    return 0;
}