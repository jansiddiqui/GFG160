#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right =NULL;
    }
};

bool dfs(Node *root, unordered_set<int> &st, int target){
    if(root == NULL){
        return false;
    }

    if(st.find(target - root->data) != st.end()){
        return true;
    }

    st.insert(root->data);

    return dfs(root->left, st, target) || dfs(root->right, st, target);
}

bool findTarget(Node *root, int target){
    unordered_set<int> st;

    return dfs(root, st, target);
}

int main(){
    Node *root = new Node(7);
    root->left = new Node(5);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(9);

    int target = 12;

    if(findTarget(root, target)){
        cout<<"True";
    }
    else{
        cout<<"false";
    }
    return 0;
}