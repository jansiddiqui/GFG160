#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int value){
        data = value;
        left = right = nullptr;
    }
};

int countPathsUtil(Node* node, int k, int currSum, unordered_map<int, int>& prefSums){
    if(node == nullptr){
        return 0;
    }

    int paathCount = 0;
    currSum += node->data;

    if(currSum == k){
        paathCount++;
    };

    paathCount += prefSums[currSum - k];

    prefSums[currSum]++;

    paathCount += countPathsUtil(node->left, k, currSum, prefSums);
    paathCount += countPathsUtil(node->right, k, currSum, prefSums);

    prefSums[currSum]--;
    return paathCount;
}

int countAllPaths(Node* root, int k){
    unordered_map<int, int> prefSums;

    return countPathsUtil(root, k, 0, prefSums);


}

int main(){
    Node* root = new Node(8);
    root->left =  new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->right = new Node(2);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(-2);
    root->left->right->right = new Node(1);

    int k = 7;

    cout << countAllPaths(root, k) << endl;
    return 0;
}