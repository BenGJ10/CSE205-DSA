/* In a grocery store, customers join a single queue to check out. Implement a system using a linked list 
   to manage this queue. When displaying, the order should be reversed, so the first customer to join 
   appears last. The program should allow customers to join the queue and display the reversed queue. */
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        this->data = val;
        this->next = nullptr;
    }
};
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if(isEmpty()){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }

    void reverseDisplay(Node* node) {
        if(node == nullptr){
            return;
        }
        // Recursively call the function to reach the end of the list
        reverseDisplay(node->next);
        cout << node->data << " ";
    }
    void display(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;            
        } else{
            cout << "Queue: ";
            reverseDisplay(front);
            cout << endl;
        }
    }
};

int main() {
    Queue queue;
    int numElements;
    cin >> numElements;
    for (int i = 0; i < numElements; i++) {
        int element;
        cin >> element;
        queue.enqueue(element);
    }

    queue.display();
    return 0;
}