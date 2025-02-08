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

void collectBoundaryLeft(Node *root, vector<int> &res){
    if(root == nullptr){
        return;
    }

    Node *curr = root;
    while(!isLeaf(curr)){
        res.push_back(curr->data);
        if(curr->left){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
}

void collectLeaves(Node* root, vector<int>& res){
    Node* current = root;

    while(current){
        if(current->left == nullptr){
            if(current->right == nullptr){
                res.push_back(current->data);
            }
            current = current->right;
        }
        else{
            Node* predecessor = current->left;
            while(predecessor->right && predecessor->right != current){
                predecessor = predecessor->right;
            }

            if(predecessor->right == nullptr){
                predecessor->right = current;
                current = current->left;
            }
            else{
                if(predecessor->left == nullptr){
                    res.push_back(predecessor->data);
                }
                predecessor->right = nullptr;
                current = current->right;
            }
        }
    }
}

void collectBoundaryRight(Node *root, vector<int> &res){
    if(root == nullptr){
        return;
    }

    Node *curr = root;
    vector<int> temp;
    while(!isLeaf(curr)){
        temp.push_back(curr->data);
        if(curr->right){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    for(int i = temp.size() - 1; i>=0; --i){
        res.push_back(temp[i]);
    }
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
    Node *root = new Node(20);
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