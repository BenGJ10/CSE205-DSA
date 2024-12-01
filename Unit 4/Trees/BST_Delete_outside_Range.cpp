/* Implement a function that removes nodes from the tree that fall outside a specified range defined by 
   a minimum and maximum value. */
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insertNode(Node* root, int val){
    Node* newNode = new Node(val);
    if(root == nullptr){
        return newNode;
    }
    if(val < root->data){
        root->left = insertNode(root->left, val);
    } else if(val > root->data){
        root->right = insertNode(root->right, val);
    }
    return root;
}

void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

Node* removeOutsideRange(Node* root, int min, int max){
    if(root == nullptr){
        return;
    }
    root->left = removeOutsideRange(root->left, min, max);
    root->right = removeOutsideRange(root->right, min, max);
    // If a node’s value is less than min, its entire left subtree can be discarded, 
    // and the right subtree should replace the node.
    if(root->data < min){
        Node* rightChild = root->right;
        delete root;
        return rightChild;
    }
    // If a node’s value is greater than max, its entire right subtree can be discarded, 
    // and the left subtree should replace the node.
    if(root->data > max){
        Node* leftChild = root->left;
        delete root;
        return leftChild;
    }
    return root;
}
int main(){
    Node* root = nullptr;
    int data, min, max;
    while(true){
        cin >> data;
        if(data == -1){
            break;
        }
        root = insertNode(root, data);
    }
    cin >> min >> max;
    removeOutsideRange(root, min, max);
    inOrderTraversal(root);
    return 0;
}