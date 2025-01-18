#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    Node(int new_data){
        data = new_data;
        next = nullptr;
    }
};

Node *reverseList(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

void printList(Node *node){
    while(node != nullptr){
        cout << " " << node->data;
        node = node->next;
    }
}
int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Provided Linked List: ";
    printList(head);

    head = reverseList(head);

    cout << "\nReversed Linked List: ";
    printList(head);
    return 0;
}