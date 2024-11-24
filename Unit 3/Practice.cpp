// Perform push(), pop(), top(), size(), display() operations in Stack using Linked List

#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int d){
        this->data = d;
        this->next = nullptr;
    }
};
class Stack{
    Node* top;
public:
    Stack(){
        top = nullptr;
    }
    void push(int data){
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        cout << data << " pushed successfully into the stack." << endl;
    }
    void pop(){
        if(top == nullptr){
            cout << "Stack is empty." << endl;
            return;
        }
    }
};
int main(){

    return 0;
}