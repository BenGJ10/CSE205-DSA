// Develop an online order processing program, which efficiently manages incoming orders.
// Use the queue data structure using array and implement it.
#include <iostream>
#define max 5
using namespace std;
class Queue{
public:
    int orders[max];
    int front, rear;

    Queue(){
        front = -1;
        rear = -1;
    }
    bool isFull(){
        return rear == max - 1;
    }
    bool isEmpty(){
        return front == -1 || front > rear;
    }
    void Enqueue(int id){
        if(isFull()){
            cout << "Queue is full." << endl;
        }else{
            if(front == -1) front = 0;
            rear++;
            orders[rear] = id;
        }
    }
    void Dequeue(){
        if(isEmpty()){
            cout << "Queue is empty." << endl;
        } else{
            cout << "Order Id " << orders[front] << " processed and removed." << endl;
            front++;
        }
    }
    void displayQueue(){
        if(isEmpty()){
            cout << "Queue is empty." << endl;
        }
        else{
            cout << "Order IDs in the queue are: ";
            for(int i = front; i <= rear; i++){
                cout << orders[i] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Queue q;
    int choice, orderID;
    while (true) {
        cout << "\n1. Add Order (Enqueue)" << endl;
        cout << "2. Process Order (Dequeue)" << endl;
        cout << "3. Display Orders in Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Order ID to add: ";
                cin >> orderID;
                q.Enqueue(orderID);
                break;

            case 2:
                q.Dequeue();
                break;

            case 3:
                q.displayQueue();
                break;

            case 4:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}