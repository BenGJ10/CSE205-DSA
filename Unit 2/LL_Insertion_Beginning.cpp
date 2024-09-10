// Inserting an element at the begining of the Linked List and Traversing
#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
void insertAtBeginLL(struct Node **head, int element){
    // Base address of newly created node will be stored in newNode
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = *head;  
    *head = newNode;
    
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
        insertAtBeginLL(&head, element);
    }
    printLL(head);
    return 0;
}
