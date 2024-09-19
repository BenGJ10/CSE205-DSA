// Given a singly linked list. The task is to check if the given linked list is palindrome or not.
#include <iostream>
#include <stack>
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
void insertAtEnd(Node** head, int data){
    Node* newNode = new Node(data);
    if((*head) == nullptr){
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
bool isPalindrome(Node* head){
    if(head == nullptr || head->next == nullptr){
        return true;
    }
    Node* curr = head;
    stack<int> s;
    while(curr != nullptr){
        s.push(curr->data);
        curr = curr->next;
    }
    Node* temp = head;
    while(temp != nullptr){
        int elem = s.top();
        s.pop();
        if(temp->data != elem){
            return false;
        }
        temp = temp->next;
    }
    return true;
}
int main(){
    int nodes;
    cin >> nodes;
    Node* head = nullptr;
    for(int i = 0; i < nodes; i++){
        int val;
        cin >> val;
        insertAtEnd(&head, val);
    }
    if(isPalindrome(head)){
        cout << "Linked List is Palindrome." << endl;
    }
    else{
        cout << "Linked List is not Palindrome." << endl;
    }
    return 0;
}