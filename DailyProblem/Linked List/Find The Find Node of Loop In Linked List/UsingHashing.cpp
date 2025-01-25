#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

Node* findFirstNode(Node* head){
    unordered_set<Node*> st;
    Node* currNode = head;

    while(currNode != nullptr){
        if(st.find(currNode) != st.end()){
            return currNode;
        }
        st.insert(currNode);
        currNode = currNode->next;
    }
    return nullptr;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(4);
    head->next->next->next = new Node(20);
    head->next->next->next->next = head;

    Node* loopNode = findFirstNode(head);

    if(loopNode){
        cout << loopNode->data;
    }
    else{
        cout << -1;
    }
    return 0;
}