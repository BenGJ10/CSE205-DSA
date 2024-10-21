/* Shakthi is assigned to design and implement a program that simulates a customer queue system for a  
   business. The program should allow users to enqueue customer IDs, dequeue customer IDs and display 
   the current customer queue.
   Implement the queue using linked lists for Shakthi to manage the customers in line at the counter. */

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
public:
    Node* front;
    Node* rear;

    Queue(){
        this->front = nullptr;
        this->rear = nullptr;
    }

    bool isEmpty(){
        return (front == nullptr);
    }

    void enqueue(int data){
        Node* newNode = new Node(data);
        if(rear){
            rear->next = newNode;
        }
        rear = newNode;
        if(!front){
            front = newNode;
        }
    }

    bool dequeue(int &data){
        if(isEmpty()){
            return false;
        }
        Node* temp = front;
        data = front->data;
        front = front->next;
        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;
        return true;
    }

    void display(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "IDs in the Queue are: ";
        Node* temp = front;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        } 
        cout << endl;
    }
};
int main(){
    Queue q;
    int id, option;
    
    while(true){
        cin >> option;
        switch(option){
            case 1:
                cin >> id;
                q.enqueue(id);
                cout << "ID " << id << " is enqueued" << endl;
                break;
            case 2:
                if(q.dequeue(id)){
                    cout << "Dequeued ID " << id << endl;
                } else{
                    cout << "Queue is empty" << endl;
                }
                break;
            case 3:
                q.display();
                break;
            case 0:
                cout << "Exiting the program..." << endl;
                return 0;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    }
    return 0;
}