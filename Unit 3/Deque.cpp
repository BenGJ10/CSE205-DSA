/* Olivia is working on a data processing project that involves analyzing a list of user IDs. 
   As part of her task, she needs to display the user IDs without duplicates using a double-ended queue.
   Write a program that Olivia can use to print the user IDs without duplicates from the deque. */
#include <iostream>
#include <unordered_set>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
struct Deque{
    Node* front;
    Node* rear;
};
void initDeque(Deque* dq){
    dq->front = nullptr;
    dq->rear = nullptr;
}
bool isEmpty(Deque* dq){
    return dq->front == nullptr;
}
void pushBack(Deque* dq, int data){
    Node* newNode = new Node{data, nullptr, nullptr};
    if(isEmpty(dq)){
        dq->front = newNode;
        dq->rear = newNode;
    } else{
        dq->rear->next = newNode;
        newNode->prev = dq->rear;
        dq->rear = newNode;
    }
}
int popFront(Deque* dq){
    if(isEmpty(dq)){
        return -1;
    }
    Node* temp = dq->front;
    int data = temp->data;
    dq->front = dq->front->next;
    
    if(dq->front != nullptr){
        dq->front->prev = nullptr;  // Set prev of new front to nullptr
    } else{
        dq->rear = nullptr; // If the deque is now empty, set rear to nullptr
    }
    delete temp;
    return data;
}
int main(){
    Deque dq;
    initDeque(&dq);
    int num;
    while(true){
        cin >> num;
        if(num == -1){
            break;
        }
        pushBack(&dq, num);
    }
    unordered_set<int> unique;
    Node* curr = dq.front;
    while(curr != nullptr){
        if(unique.find(curr->data) == unique.end()){
            unique.insert(curr->data);
            cout << curr->data << " ";
        }
        curr = curr->next;
    }
    cout << endl;
    return 0;
}