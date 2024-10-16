// Reverse a single Linked List
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = nullptr; 
    }
};
void insertAtEnd(Node** head, int data){
    Node* newNode = new Node(data);
    if((*head) == nullptr){
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
Node* reverseLL(Node** head){
    Node* curr = *head;
    Node* prev = nullptr;
    while(curr != nullptr){
        Node* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}
void printLL(Node* head){
    if(head == nullptr){
        cout << "Linked List is empty.";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    int nodes;
    cin >> nodes;
    Node* head = nullptr;
    for(int i = 0; i < nodes; i++){
        int val;
        cin >> val;
        insertAtEnd(&head, val);
    }
    cout << "Linked List: ";
    printLL(head);
    reverseLL(&head);
    cout << "Linked List after reversing: ";
    printLL(head);
    return 0;
}
