#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

bool search(Node* root, int key, Node* temp){
    if(root == nullptr){
        return false;
    }

    Node* curr = root;

    while(curr != NULL){
        if(curr->data == key && curr != temp){
            return true;
        }
        else if(key < curr->data){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    return false;
}

bool findTargetRec(Node* root, Node* curr, int target){
    if(curr == NULL){
        return false;
    }

    int comp = target - curr->data;
    if(search(root, comp, curr)){
        return true;
    }

    return findTargetRec(root, curr->left, target) || findTargetRec(root, curr->right, target);
}

bool findTarget(Node* root, int target){
    return findTargetRec(root, root, target);
}

int main(){
    Node* root = new Node(15);
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