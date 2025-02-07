#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

vector<int> inOrder(Node* root){
    vector<int> res;
    Node* curr = root;

    while(curr!=nullptr){
        if(curr->left == nullptr){
            res.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right != nullptr && prev->right != curr){
                prev = prev->right;
            }
            if(prev->right == nullptr){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = nullptr;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return res;
}

int main(){
    Node* root  = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int>  res = inOrder(root);

    for(int data : res){
        cout << data <<" ";
    }
    return 0;
}