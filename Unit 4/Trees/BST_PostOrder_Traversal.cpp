/* John, a computer science student, is learning about binary search trees (BST) and their properties. 
   He decides to write a program to create a BST, display it in post-order traversal, 
   and find the minimum value present in the tree. Help him by implementing the program. */
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
Node* insertNode(Node* root, int data){
    if(root == nullptr){
        return new Node(data);
    }
    if(data < root->data){
        root->left = insertNode(root->left, data);
    }   else if(data > root->data){
        root->right = insertNode(root->right, data);
    }
    return root;
}
void postOrderTraversal(Node* root){
    if(root == nullptr) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
int findMinValue(Node* root) {
    Node* temp = root;
    while(temp && temp->left != nullptr){
        temp = temp->left;
    }
    return temp->data;
}
int main(){
    Node* root = nullptr;
    int n, data;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insertNode(root, data);
    }

    postOrderTraversal(root);
    cout << endl;

    int minValue = findMinValue(root);
    cout << "The minimum value in the BST is: " << minValue;

    return 0;
}