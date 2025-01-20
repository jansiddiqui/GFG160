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
    Node* dummy = new Node(-1);
    Node* curr = dummy;

    while(head1 != nullptr && head2 != nullptr){
        if(head1->data <= head2->data){
            curr->next = head1;
            head1 = head1->next;
        }else{
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    if(head1 != nullptr){
        curr->next = head1;
    }else{
        curr->next = head2;
    }
    return dummy->next;
}

void printList(Node* head){
    while(head != nullptr){
        cout<<head->data;
        if(head->next != nullptr){
            cout<<" ";
        }
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node* head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);
    head1->next->next->next = new Node(40);

    Node* head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    Node* res = sortedMerge(head1, head2);

    printList(res);

    return 0;
}