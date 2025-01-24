#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        this->data = x;
        this->next = NULL;
    }
};

bool detectLoop(Node* head){
    Node *slow = head, *fast = head;

    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = head->next;

    if(detectLoop(head)){
        cout<<"the loop is avilable";
    }
    else{
        cout<<"loop is not avilable";
    }
    return 0;
}