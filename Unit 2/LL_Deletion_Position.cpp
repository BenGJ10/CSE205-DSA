/* Suppose you are working on a student management system for a university, and you need to 
implement a deletion functionality for a grounded header linked list to manage student records. 
Write a program to implement deletion logic with multiple deletions based on user input. */
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
Node* createNode(int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}
void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if((*head)->next == nullptr){
        (*head)->next = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;  
}
void deleteNode(Node* head, int value){
    Node* curr = head->next;
    Node* prev = head;
    while(curr != nullptr){
        if(curr->data == value){
            Node* temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
}
void printLL(Node* head){
    if(head == nullptr){
        cout << "Linked List is empty.";
        return;
    }
    Node* temp = head->next;
    cout << "Linked List after deletion: ";
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    int nodes;
    cin >> nodes;
    Node* head = new Node();
    head->next = nullptr;
    int value;
    for(int i = 0; i < nodes; i++){
        cin >> value;
        insertAtEnd(&head, value);
    }
    cin >> value;
    deleteNode(head, value);
    printLL(head);
    return 0;
}