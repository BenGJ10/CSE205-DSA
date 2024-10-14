/* Divu wants a program to analyze a binary tree by traversing it in two different ways. 
   The program begins by prompting for an integer n, indicating the number of nodes in the binary tree. 
   Divu then provides n integers representing the values of these nodes. The program constructs the binary 
   tree from the provided values and performs two types of traversals:

   Forward In-order Traversal: It traverses the binary tree in order, printing each node's value as 
   it visits.
   Reverse In-order Traversal: It traverses the binary tree in order but prints each node's value 
   in reverse order. */

// Data Structure used -> Array

#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void printInOrder(Node* node){
    if(node == nullptr){
        return;
    }
    printInOrder(node->left);
    cout << node->data << " ";
    printInOrder(node->right);
}

void printInOrderReverse(Node* node){
    if(node == nullptr){
        return;
    }
    printInOrderReverse(node->right);
    cout << node->data << " ";
    printInOrderReverse(node->left);
} 

Node* insertLevelOrder(int arr[], Node* root, int i, int n){
    if(i < n){
        Node* temp = new Node(arr[i]);
        root = temp;

        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}   

int main(){
    int size;
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    Node* root = nullptr;
    root = insertLevelOrder(arr, root, 0, size);
    cout << "InOrder Traversal: ";
    printInOrder(root);
    cout << endl;
    cout << "InOrder Traversal in Reverse: ";
    printInOrderReverse(root);
    cout << endl;
    return 0;
}