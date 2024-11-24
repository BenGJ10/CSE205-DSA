#include <iostream>
using namespace std;
class Stack{

    int *stack;
    int size;
    int top;
public:
    Stack(int size){
        this->size = size;
        stack = new int[size];
        this->top = -1;
    }

    void push(int value) {
        if (top == size - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        stack[++top] = value;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return stack[top--];
    }

    int peek() {
        if (top == -1) {
            return -1;
        }
        return stack[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

void nextGreaterElement(int prices[], int n){
    Stack s(n);
    int nge[n];
    for (int i = 0; i < n; i++) {
        nge[i] = -1;
    }
    
    for(int i = 0; i < n; i++){
        while(!s.isEmpty() && prices[s.peek()] < prices[i]){
            nge[s.pop()] = prices[i];
        }
        s.push(i);
    }
    
    for (int i = 0; i < n; i++) {
        cout << prices[i] << " " << nge[i] << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int prices[n];

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    nextGreaterElement(prices, n);

    return 0;
}