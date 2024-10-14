/* In a busy hospital, beds are allocated to patients as they arrive. You are an administrator at a hospital
   in charge of managing the allocation of beds. 
   You need to perform the following tasks:
   1. Allocate Beds: As new patients arrive, their beds are assigned and pushed onto the stack.
   2. View Allocation: After allocating a series of beds, you need to view the stack of beds in the order 
    they were allocated (i.e., from the most recently allocated to the oldest).
   3. Sort Beds: To optimize bed management, you need to sort the stack of bed IDs in ascending order based 
    on their IDs.
    Use Stack data structure made with Linked List */

#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
class Stack{
    Node* top;
public:
    Stack() : top(nullptr) {}

    void push(int val){
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
    void printStack(){
        Node* temp = top;
        while(temp != nullptr){
            cout << temp->data  << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void sortPrintStack(){
        // Converting stack into array
        int bedArray[10];
        int count = 0;
        Node* temp = top;
        while(temp != nullptr){
            bedArray[count++] = temp->data;
            temp = temp->next;
        }
        sort(bedArray, bedArray + count);
        for(int i = 0; i < count; i++){
            cout << bedArray[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    Stack stack;
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        int id;
        cin >> id;
        stack.push(id);
    }
    cout << "Original Bed IDs: ";
    stack.printStack();
    cout << "Bed IDs after sorting: ";
    stack.sortPrintStack();
    return 0;
}