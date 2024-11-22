/* Sita is working on implementing a binary search tree (BST). She wants to write functions to insert 
   nodes into the BST, delete nodes from the BST (the number of nodes she wants to delete and then request 
   the values of those nodes), and perform an in-order traversal of the BST to display the updated BST. 
   Help her in implementing the function to delete the specified nodes. */

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
    } else if(data > root->data){
        root->right = insertNode(root->right, data);
    }
    return root;
} 

void inOrderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Finding the minimum element in a BST -> bottom leftmost element
Node* findMin(Node* root){
    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int val){
    if(root == nullptr){
        return root;
    }
    if(val < root->data){
        root->left = deleteNode(root->left, val);
    } else if(val > root->data){
        root->right = deleteNode(root->right, val);
    } else{ // If root == val
        // If left child is empty
        if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        } // If right child is empty 
        else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        } 
        // If both left and right child is present
        Node* temp = findMin(root->right);  // Finding the smallest element in the right subtree
        // Replacing the element to delete with the inorder successor
        root->data = temp->data;
        // Deleting the inorder successor from the right subtree recursively
        root->right = deleteNode(root->right, temp->data);
        }
    return root;
}

int main(){
    Node* root = nullptr;
    int size, data;
    cin >> size;
    for(int i = 0; i < size; i++){
        cin >> data;
        root = insertNode(root, data);
    }
    cout << "Binary Search Tree before deletion: ";
    inOrderTraversal(root);
    cout << endl;

    int elem_to_delete;
    cout << "Enter node to delete: ";
    cin >> elem_to_delete;
    deleteNode(root, elem_to_delete);

    cout << "Binary Search Tree after deletion: ";
    inOrderTraversal(root);
    cout << endl;
    return 0;
}   