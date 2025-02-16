#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int X){
        data = X;
        left = right = nullptr;
    }
};

vector<int> serialize(Node *root){
    vector<int> arr;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *curr = q.front();
        q.pop();

        if(curr == nullptr){
            arr.push_back(-1);
            continue;
        }

        arr.push_back(curr->data);

        q.push(curr->left);
        q.push(curr->right);


    }
    return arr;
}

Node *deserialize(vector<int> &arr){

    if(arr[0] == -1){
        return nullptr;
    }

    Node *root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();

        if(arr[i] != -1){
            Node *left = new Node(arr[i]);
            curr->left = left;
            q.push(left);

        }
        i++;

        if(arr[i] != -1){
            Node *right = new Node(arr[i]);
            curr->right = right;
            q.push(right);
        }
        i++;
    }
    return root;
}

void printLevelOrder(Node *root){
    if(root == nullptr){
        cout << "N ";
        return;
    }

    queue<Node *> qq;
    qq.push(root);
    int nonNull = 1;

    while(!qq.empty() && nonNull > 0){
        Node *curr = qq.front();
        qq.pop();

        if(curr == NULL){
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
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    vector<int> arr = serialize(root);
    Node* res = deserialize(arr);

    printLevelOrder(res);
}