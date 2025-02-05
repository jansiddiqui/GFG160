#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left =nullptr;
        right = nullptr;
    }
};

void mirror(Node* root){
    if(root == nullptr){
        return ;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        swap(curr->left, curr->right);

        if(curr->left != nullptr){
            q.push(curr->left);
        }
        if(curr->right != nullptr){
            q.push(curr->right);
        }
    }
}

void levelOrder(Node *root){
    if(root == nullptr){
        cout << "N ";
        return ;
    }

    queue<Node*> qq;
    qq.push(root);

    while(!qq.empty()){
        Node *curr = qq.front();
        qq.pop();

        if(curr == nullptr){
            cout << "N ";
            continue;
        }
        cout << (curr->data) << " ";
        qq.push(curr->left);
        qq.push(curr->right);
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    mirror(root);

    levelOrder(root);

    return 0;
}