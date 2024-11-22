// Perform all BST related operations including Insertion, Deletion and Traversal
#include<iostream>
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
    Node* newNode = new Node(data);
    if(root == nullptr){
        return newNode;
    }
    if(data < root->data){
        insertNode(root->left, data);
    } else if(data > root->data){
        insertNode(root->right, data);
    }
    return root;
}
Node* findMin(Node* root){
    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}
Node* deleteNode(Node* root, int data){
    if(root == nullptr){
        return root;
    }
    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }else{
        if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
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