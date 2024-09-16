/* Fin is creating a linked list to store his favorite numbers in the order he inputs them. 
He wants to continue adding numbers until he inputs a negative number, which will signal the end of the input.
After the input ends, he wants to print all the numbers in the linked list in the order they were added. */
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
Node* insertAtEnd(Node* head, int val){
    Node* newNode = createNode(val);
    // If there is no head, initialize the newly created node as head
    if(head == nullptr){
        return newNode;
    }
    Node* temp = head;
    // Traversing till the last node
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
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
    Node* head = nullptr;
    int num;
    while(true){
        cin >> num;
        // We need to exit the program when it encounters a negative number
        if(num < 0){
            break;
        }
        head = insertAtEnd(head, num);
    }
    printLL(head);
    return 0;
}