// Inserting elements at the front of the Linked List and printing it out
#include <iostream>
using namespace std;
class Node{
public:    
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};
void insertionAtFront(Node** head, int val){
    Node* newNode = new Node(val);
    if((*head) == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}
void printLL(Node* head){
    if(head == NULL){
        cout << "Linked List is empty." << endl;
        return;
    }
    Node* temp = head;
    cout << "Current Linked List: ";
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
        insertionAtFront(&head, val);
        printLL(head);
    }
    return 0;
}