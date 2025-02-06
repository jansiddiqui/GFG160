#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void printLevelOrder(Node *root){
    if(root == nullptr){
        cout << "N ";
        return;
    }

    queue<Node *> qq;
    qq.push(root);
    int nonNull = 1;

    while(!qq.empty() && nonNull>0){
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

int search(vector<int> &inorder, int value, int left, int right){
    for(int i=left;i<=right;i++){
        if(inorder[i] == value){
            return i;
        }
    }
    return -1;
}

Node *buildTreeRecur(vector<int> &inorder, vector<int> &preorder, int &preIndex,  int left, int right){
    if(left > right){
        return nullptr;
    }

    int rootVal = preorder[preIndex];
    preIndex++;

    Node *root = new Node(rootVal);

    int index = search(inorder, rootVal, left, right);
    root->left = buildTreeRecur(inorder, preorder, preIndex, left, index - 1);
    root->right = buildTreeRecur(inorder, preorder, preIndex, index + 1, right);
    return root;
}

Node *buildTree(vector<int> &inorder, vector<int> &preorder){
    int preIndex = 0;
    Node *root = buildTreeRecur(inorder, preorder, preIndex, 0, preorder.size() - 1);
    return root;
}

int main(){
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};
    Node *root = buildTree(inorder, preorder);

    printLevelOrder(root);

    return 0;
}