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
void insertAtEnd(Node** head, int value) {
    Node* newNode = new Node(value);
    if((*head) == nullptr){
        (*head) = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;  
}
void deleteEvenPositionNodes(Node** head){
    if(*head == nullptr){
        return;
    }
    Node* prev = nullptr;
    Node* curr = *head;
    int position = 1;
    while(curr != nullptr){
        if(position % 2 == 0){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
        position++;
    }
}

void printLL(Node* head){
    if(head == nullptr){
        cout << "Linked List is empty.";
        return;
    }
    Node* temp = head;
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
    Node* head = nullptr;
    int value;
    for(int i = 0; i < nodes; i++){
        cin >> value;
        insertAtEnd(&head, value);
    }
    cout << "Linked List before deletion: ";
    printLL(head);
    deleteEvenPositionNodes(&head);
    cout << "Linked List after deletion: ";
    printLL(head);
    return 0;
}