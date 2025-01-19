#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int new_data){
        data = new_data;
        next = nullptr;
    }
};

Node *rotate(Node *head, int k){
    if(k == 0 || head == nullptr){
        return head;
    }

    for(int i=0;i<k;++i){
        Node *curr = head;
        while(curr->next != nullptr){
            curr = curr->next;
        }

        curr->next = head;
        curr == curr->next;
        head = head->next;
        curr->next = nullptr;
    }
    return head;
}

void printList(Node *node){
    while(node != nullptr){
        cout << node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head = rotate(head, 6);
    printList(head);

    return 0;
}