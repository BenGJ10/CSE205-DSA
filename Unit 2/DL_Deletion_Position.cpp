// Delete a particular Node from the given Doubly Linked List
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
void insertionAtFront(Node** head, int val){
    Node* newNode = new Node(val);
    if((*head) == nullptr){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}
void deleteNode(Node** head, Node* delNode){
    if((*head) == nullptr || delNode == nullptr){
        return;
    }
    if((*head) == delNode){
        *head = delNode->next;
    }
    if(delNode->prev != nullptr){
        delNode->prev->next = delNode->next;
    }
    if(delNode->next != nullptr){
        delNode->next->prev = delNode->prev;
    }
    delete(delNode);
}
void deleteNodeAtGivenPos(Node** head, int pos){
    Node* temp = *head;
    for(int i = 1; i < pos && temp != nullptr; i++){
        temp = temp->next;
    }
    if(temp == nullptr) return;
    deleteNode(head, temp);
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
    Node* head = nullptr;
    int n, data;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data;
        insertionAtFront(&head, data);
    }
    
    cout << "Before deletion: ";
    printLL(head);

    int pos;
    cin >> pos;
    deleteNodeAtGivenPos(&head, pos);

    cout << "After deletion: ";
    printLL(head);
    return 0;
}