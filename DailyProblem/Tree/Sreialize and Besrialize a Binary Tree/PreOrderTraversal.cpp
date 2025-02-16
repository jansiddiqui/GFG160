#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data  = x;
        left = right = NULL;
    }
};

void serializePreOrder(Node* root, vector<int> &arr){
    if(root == NULL){
        arr.push_back(-1);
        return;
    }

    arr.push_back(root->data);

    serializePreOrder(root->left, arr);
    serializePreOrder(root->right, arr);
}

vector<int> serialize(Node *root){
    vector<int> arr;
    serializePreOrder(root, arr);
    return arr;
}
Node* deserializePreOrder(int &i, vector<int> &arr){
    if(arr[i] == -1){
        i++;
        return NULL;
    }

    Node* root = new Node(arr[i]);
    i++;

    root->left  = deserializePreOrder(i, arr);
    root->right = deserializePreOrder(i, arr);

    return root;
}

Node *deSerialize(vector<int> &arr){
    int i = 0;
    return deserializePreOrder(i, arr);
}

void printLevelOrder(Node *root){
    if(root == NULL){
        cout << "N ";
        return;
    }

    queue<Node *> qq;
    qq.push(root);
    int nonNull = 1;

    while(!qq.empty() && nonNull > 0){
        Node *curr = qq.front();
        qq.pop();

        if(curr == nullptr){
            cout << "N ";
            continue;
        }

        nonNull--;

        cout << (curr->data) << " ";
        qq.push(curr->left);
        qq.push(curr->right);
        if(curr->left){
            nonNull++;
        }
        if(curr->right){
            nonNull++;
        }
    }
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(60);

    vector<int> arr = serialize(root);
    Node* res = deSerialize(arr);

    printLevelOrder(res);
}