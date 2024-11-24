// Perform enqueue(), dequeue(), peek(), disply() operations in Queue using Linked List
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
class Queue{
    Node* front;
    Node* rear;
public:
    Queue(){
        front = nullptr;
        rear = nullptr;
    }
    bool isEmpty(){
        return front == nullptr;
    }
    void enqueue(int data){
        Node* newNode = new Node(data);
        if(isEmpty()){
            front = newNode;
            rear = newNode;
        } else{
            rear->next = newNode;
            rear = newNode;
        }
        cout << data << " enqueued successfully." << endl;
    }
    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty.";
            return;
        }
        Node* temp = front;
        int data = temp->data;
        front = front->next;
        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;
        cout << data << " dequeued successfully." << endl;
    }
    void peek(){
        if(isEmpty()){
            cout << "Queue is empty.";
            return;
        }
        cout << "Front element is: " << front->data << endl;
    }
    void display(){
        if(isEmpty()){
            cout << "Queue is empty.";
            return;
        }
        Node* temp = front;
        cout << "Elements in the queue are: ";
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    Queue q;
    int choice, data;
    while(true){
        cin >> choice;
        switch(choice){
            case 1:
                cin >> data;
                q.enqueue(data);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return 0;
}