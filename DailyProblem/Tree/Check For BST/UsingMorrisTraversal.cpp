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

bool isBST(Node* root){
    Node *curr = root;
    Node *pre = nullptr;
    int prevValue = INT_MIN;

    while(curr != nullptr){
        if(curr->left == nullptr){
            if(curr->data <= prevValue){
                return false;
            }
            prevValue = curr->data;
            curr = curr->right;
        }else{
            pre = curr->left;
            while(pre->right != nullptr && pre->right != curr){
                pre = pre->right;
            }
            if(pre->right == nullptr){
                pre->right = curr;
                curr = curr->left;
            }else{
                pre->right = nullptr;
                if(curr->data <= prevValue){
                    return false;
                }
                prevValue = curr->data;
                curr = curr->right;
            }
        }
    }
    return true;
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    if(isBST(root)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}