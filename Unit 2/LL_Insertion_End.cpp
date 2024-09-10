// Inserting an element at the begining of the Linked List and Traversing
#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
void insertAtEndLL(struct Node **head, int element){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* lastNode = *head;
    newNode->data = element;
    newNode->next = nullptr;
    // If there are no elements
    if(*head == NULL){
        *head = newNode;
        return;
    }
    else{
        // Start traversing from first node to the last node
        while(lastNode->next != NULL){
            lastNode = lastNode->next;
        }
        // Reached the last node
        lastNode->next = newNode;
    }
     
}
void printLL(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    struct Node *head = NULL;
    int size, element;
    cin >> size;
    for(int i = 0; i < size; i++){
        cin >> element;
        insertAtEndLL(&head, element);
    }
    printLL(head);
    return 0;
}
