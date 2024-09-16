// Delete nodes in a Linked List that appear more than once.
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
void insertNode(Node** head, int val){
    Node* newNode = createNode(val);
    if(*head == nullptr){
        *head = newNode;
    }
    else{
        Node* temp = *head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void deleteDuplicates(Node** head){
    if(*head == nullptr){
        return;
    }
    Node* currNode = *head;
    while(currNode != NULL){
        Node* temp = currNode;
        while(temp->next != NULL){
            if(temp->next->data == currNode->data){
                Node* dupNode = temp->next;
                temp->next = temp->next->next;
                delete dupNode;
            }
            else{
                temp = temp->next;
            }
        }
        currNode = currNode->next;
    }
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
        insertNode(&head, val);
    }
    cout << "Original Linked List: ";
    printLL(head);
    deleteDuplicates(&head);
    cout << "Linked List after duplicates deletion: ";
    printLL(head);
    return 0;
}