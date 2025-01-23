#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* random;

    Node(int x){
        data = x;
        next = random = NULL;
    }
};

Node* cloneLinkedList(Node* head){
    unordered_map<Node*, Node*> mp;
    Node *curr = head;

    while(curr != NULL){
        mp[curr] = new Node(curr->data);
        curr = curr->next;
    }
    curr = head;

    while(curr != NULL){
        mp[curr]->next = mp[curr->next];
        mp[curr]->random = mp[curr->random];
        curr = curr->next;
    }
    return mp[head];
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data << "(";
        if(head->random){
            cout << head->random->data << ")";
        }else{
            cout << "null" << ")";
        }
        if(head->next != NULL){
            cout << "->";
        }
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    cout << "Original linked list:\n";
    printList(head);

    Node* clonedList = cloneLinkedList(head);

    cout << "Cloned linked list:\n";

    printList(clonedList);

    return 0;
}