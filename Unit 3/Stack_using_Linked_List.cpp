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
    void size(){
        if(top == nullptr){
            cout << "Stack is empty." << endl;
            return;
        }
        int count = 0;
        Node* temp = top;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        cout << "No of elements in the stack are: " << count << endl;
    }
    void pop(){
        if(top == nullptr){
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped " << temp->data << " out of the stack." << endl;
        delete temp;
    }
    void topElement(){
        if(top == nullptr){
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element is: " << top->data << endl;
    }
    void display(){
        if(top == nullptr){
            cout << "Stack is empty. No elements to print." << endl;
        }
        Node* temp = top;
        cout << "Elements in the stack are: ";
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    Stack s;
    int choice, data;
    while(true){
        cin >> choice;
        switch(choice){
            case 1:
                cin >> data;
                s.push(data);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.size();
                break;
            case 4:
                s.topElement();
                break;
            case 5:
                s.display();
                break;
            case 6:
                cout << "Exiting the program..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    return 0;
}