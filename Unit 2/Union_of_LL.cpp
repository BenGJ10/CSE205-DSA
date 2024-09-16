/* Using two given Linked Lists, your task is to create a new Linked List that represents the Union of
   the two given Linked Lists, while ensuring elements are distinct and sorted in ascending order. */
#include <iostream>
#include <vector>
using namespace std;
// Creating Class of node for Linked List
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
void sortedInsertion(Node** head, Node* newNode){
    if(*head == NULL || newNode->data < (*head)->data){
        newNode->next = *head;
        *head = newNode;
    }else{
        Node* temp = *head;
        while(temp->next != NULL && temp->next->data < newNode->data){
            temp = temp->next;
        }
        newNode->next = temp->next;     // temp->next->data > newNode->data
        temp->next = newNode;
    }
}
void printLL(Node* head){
    if(head == NULL){
        cout << "Empty Linked List!" << endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
bool nodeExists(Node* head, int data){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == data){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
Node* makeUnion(Node* head1, Node* head2){
    Node* result = NULL;
    Node* temp1 = head1;
    while(temp1 != NULL){
        if(!nodeExists(result, temp1->data)){
            Node* newNode = createNode(temp1->data);
            sortedInsertion(&result, newNode);
        }
        temp1 = temp1->next;
    }
    Node* temp2 = head2;
    while(temp2 != NULL){
        if(!nodeExists(result, temp2->data)){
            Node* newNode = createNode(temp2->data);
            sortedInsertion(&result, newNode);
        }
        temp2 = temp2->next;
    }
    return result;
}
int main(){
    int n1, n2;
    cout << "Enter first Linked List size: ";
    cin >> n1;
    Node* head1 = NULL;
    for(int i = 0; i < n1; i++){
        int data;
        cin >> data;
        Node* newNode = createNode(data);
        sortedInsertion(&head1, newNode);
    }
    cout << "Enter second Linked List size: ";
    cin >> n2;
    Node* head2 = NULL;
    for(int i = 0; i < n2; i++){
        int data;
        cin >> data;
        Node* newNode = createNode(data);
        sortedInsertion(&head2, newNode);
    }
    cout << "First Linked List: ";
    printLL(head1);
    cout << "Second Linked List: ";
    printLL(head2);
    Node* unionList = makeUnion(head1, head2);
    cout << "Union Linked List: ";
    printLL(unionList);

    return 0;
}
