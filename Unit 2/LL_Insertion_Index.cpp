/* Suppose you are working on a text editing application and you need to implement a feature 
that allows users to insert a character at a specific index in the text. You decide to implement 
this feature using a grounded header linked list to manage the text efficiently. */
#include <iostream>
using namespace std;
class Node{
    public:
    char data;
    Node* next;
};
Node* createNode(int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}
void insertAtPosition(Node* head, int pos, int val){
    Node* newNode = createNode(val);
    Node* temp = head;
    for(int i = 0; i < pos; i++){
        if(temp->next == nullptr){
            cout << "Invalid Position" << endl;
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    int nodes;
    char val;
    cin >> nodes;
    Node* head = createNode('\0');
    for(int i = 0; i < nodes; i++){
        cin >> val;
        insertAtPosition(head, i, val);
    }
    int position;
    cin >> position;
    cin >> val;
    insertAtPosition(head, position, val);
    cout << "Updated List: ";
    printLL(head);
    return 0;
}

