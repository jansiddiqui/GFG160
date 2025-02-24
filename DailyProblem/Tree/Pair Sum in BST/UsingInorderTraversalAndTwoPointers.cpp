#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};

void inorderTra(Node* root, vector<int>& inorder){
    if(root == NULL) return;

    inorderTra(root->left, inorder);

    inorder.push_back(root->data);

    inorderTra(root->right, inorder);
}

bool findTarget(Node* root, int target){
    vector<int> inorder;
    inorderTra(root, inorder);

    int left = 0, right = inorder.size() - 1;

    while(left<right){
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
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(9);


    int target = 12;

    if(findTarget(root, target)){
        cout << "True";
    }
    else{
        cout << "False";
    }
    return 0;
}