#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void levelOrderRec(Node* root, int level, vector<vector<int>>& res){
    if(root == nullptr)return;
    if(res.size() <= level){
        res.push_back({});
    }

    res[level].push_back(root->data);

    levelOrderRec(root->left, level+1, res);
    levelOrderRec(root->right, level+1, res);
}

vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> res;

    levelOrderRec(root, 0, res);
    return res;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->right = new Node(4);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(5);


    vector<vector<int>> res = levelOrder(root);

    for(vector<int> level : res){
        for(int data : level){
            cout<< data << " ";
        }
    }
}