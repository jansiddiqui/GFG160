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

void printLevelOrder(Node *root) {
    if (root == nullptr) {
        cout << "N ";
        return;
    }

    queue<Node *> qq;
    qq.push(root);
    int nonNull = 1;

    while (!qq.empty() && nonNull > 0) {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            cout << "N ";
            continue;
        }
        nonNull--;

        cout << (curr->data) << " ";
        qq.push(curr->left);
        qq.push(curr->right);
        if (curr->left)
            nonNull++;
        if (curr->right)
            nonNull++;
    }
}

Node *buildTreeRecur(unordered_map<int, int> &mp, vector<int> &preorder, int &preIndex, int left, int right){
    if(left > right){
        return nullptr;
    }
    int rootVal = preorder[preIndex];
    preIndex++;

    Node *root = new Node(rootVal);

    int index = mp[rootVal];

    root->left = buildTreeRecur(mp, preorder, preIndex, left, index - 1);
    root->right = buildTreeRecur(mp, preorder, preIndex, index + 1, right);
    return root;
}

Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int,int> mp;
        for (int i = 0; i < inorder.size(); i++) 
            mp[inorder[i]] = i;

        int preIndex = 0;
    Node *root = buildTreeRecur(mp, preorder, preIndex, 0, inorder.size() - 1);

    return root;
}

int main() {
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};
    Node *root = buildTree(inorder, preorder);

    printLevelOrder(root);

    return 0;
}