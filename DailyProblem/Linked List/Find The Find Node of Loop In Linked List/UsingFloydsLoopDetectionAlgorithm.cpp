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
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
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
        cout << "Loop starts at node with data: " << loopNode->data << endl;
    }
    else{
        cout << -1;
    }

    return 0;
}