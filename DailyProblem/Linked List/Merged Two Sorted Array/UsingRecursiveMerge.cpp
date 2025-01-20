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

Node* sortedMerge(Node* head1, Node* head2){
    if(head1 == nullptr){
        return head2;
    }
    if(head2 == nullptr){
        return head1;
    }

    if(head1->data <= head2->data){
        head1->next = sortedMerge(head1->next, head2);
        return head1;
    }
    else{
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
}

void printList(Node* curr){
    while(curr != nullptr){
        cout<<curr->data;
        if(curr->next != nullptr){
            cout<<" ";
        }
        curr = curr->next;
    }
    cout<<endl;
}

int main(){
    Node* head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);

    Node* head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    Node* res = sortedMerge(head1, head2);

    printList(res);

    return 0;
}