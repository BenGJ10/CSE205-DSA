/* Imagine you are organizing a game where you need to keep track of the scores of players and also 
   quickly find out the highest score among them. Use stack data structure made with Array. */
#include <iostream>
#include <climits>
using namespace std;
class Stack{
    int top;
    int arr[10];    // Max 10 elements
public:
    Stack(){
        top = -1;
    }
    void push(int val){
        if(top < 9){
            top++;
            arr[top] = val;
        } else{
            cout << "Stack is full." << endl;
        }
    }
    void pop(){
        if(top >= 0){
            top--;
        } else{
            cout << "Stack is empty" << endl;
        }
    }
    void getMax(){
        if(top == -1){
            cout << "Stack is empty" << endl;
        } else{
            int highest = INT_MIN;
            for(int i = 0; i < top; i++){
                if(arr[i] > highest){
                    highest = arr[i];
                }
            }
            cout << "Maximum value in the stack is: " << highest << endl;
        }
    }
    void printStack() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Stack stack;
    int choice, value;
    while(true){
        cin >> choice;

        switch(choice){
            case 1:
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.getMax();
                break;
            case 4:
                stack.printStack();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice" << endl;
                break;  
        }
    }
    return 0;
}