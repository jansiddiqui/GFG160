#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        this->data = x;
        this->next = nullptr;
    }
};

bool detectLoop(Node* head){
    unordered_set<Node*>st;

    while(head != nullptr){
        if(st.find(head) != st.end()){
            return true;
        }
        st.insert(head);
        head = head->next;
    }
    return false;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = head->next;

    if(detectLoop(head)){
        cout<<"Loop is available!";
    }else{
        cout<<"loop is not available";
    }
    return 0;
}