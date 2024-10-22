/*  Hansika wants to implement a program that manages a double-ended queue (deque). 
    The program should allow the insertion of elements at both the front and back of the deque, 
    and then display the contents of the deque. */
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        this->data = d;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class Deque{
public:
    Node* front;
    Node* rear;

    Deque(){
        front = nullptr;
        rear = nullptr;
    }
};
bool isEmpty(Deque* dq){
    return dq->front == nullptr;
}

void insertFront(Deque* dq, int data){
    Node* newNode = new Node(data);
    if(dq->front == nullptr){
        dq->front = newNode;
        dq->rear = newNode;
    } else{
       newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
}
void insertRear(Deque* dq, int data){
    Node* newNode = new Node(data);
    if(isEmpty(dq)){
        dq->front = newNode;
        dq->rear = newNode;
    } else{
        dq->rear->next = newNode;
        newNode->prev = dq->rear;
        dq->rear = newNode;
    }
}
void printDeque(Deque* dq){
    if(isEmpty(dq)){
        cout << "Deque is empty.";
        return;
    }
    Node* temp = dq->front;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    Deque deque;
    int element;
    cin >> element;
    insertFront(&deque, element);

    cin >> element;
    insertFront(&deque, element);

    cin >> element;
    insertRear(&deque, element);

    cin >> element;
    insertRear(&deque, element);

    cin >> element;
    insertFront(&deque, element);

    cin >> element;
    insertRear(&deque, element);

    printDeque(&deque);
    return 0;
}