#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* one;
    Node* zero;
    Node(){
        one = nullptr;
        zero = nullptr;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(int n){
        Node* curr = root;
        for(int i=31;i>=0;i--){
            int bit = (n>>i)&1;
            if(bit == 0){
                if(curr->zero == NULL){
                    curr->zero = new Node();
                }
                curr = curr->zero;
            }
            else{
                if(curr->one == NULL){
                    curr->one = new Node();
                }
                curr = curr->one;
            }
        }
    }
    int findXOR(int n){
        Node* curr = root;
        int res = 0;

        for(int i=31;i>=0;i--){
            int bit = (n>>i)&1;
            if(bit == 0){
                if(curr->one){
                    curr = curr->one;
                    res += (1 << i);
                }else{
                    curr = curr->zero;
                }
            }
            else{
                if(curr->zero){
                    curr = curr->zero;
                    res += (1 << i);
                }else{
                    curr = curr->one;
                }
            }
        }
        return res;
    }
};

int maxXOR(vector<int> &arr){
    int res = 0;
    Trie *t = new Trie();
    t->insert(arr[0]);
    for(int i=1;i<arr.size();i++){
        res = max(t->findXOR(arr[i]), res);
        t->insert(arr[i]);
    }
    return res;
}

int main(){
    vector<int> arr = {26, 100, 25, 13, 4, 14};
    cout<<maxXOR(arr);
    return 0;
}