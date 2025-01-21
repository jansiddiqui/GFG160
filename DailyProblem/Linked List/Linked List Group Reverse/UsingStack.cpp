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

Node *reverseKGroup(Node *head, int k){
    if(!head || k == 1){
        return head;
    }

    stack<Node*> st;
    Node *curr = head;
    Node *prev = nullptr;

    while(curr != nullptr){
        int count = 0;
        while(curr != nullptr && count < k){
            st.push(curr);
            curr = curr->next;
            count++;
        }
        while(!st.empty()){
            if(prev == nullptr){
                prev = st.top();
                head = prev;
                st.pop();
            }else{
                prev->next = st.top();
                prev = prev->next;
                st.pop();
            }
        }
        
    }
    prev->next = nullptr;
    return head;
}

void printList(Node *head){
    Node *curr = head;
    while(curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout<<endl;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = reverseKGroup(head, 3);

    printList(head);

    return 0;
}