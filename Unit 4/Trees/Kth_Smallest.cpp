// Find the k-th smallest element in a Binary Search Tree (BST)
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
void inOrderTraversal(Node* root, int &k, int &element){
    if(root == nullptr || k == 0){
        return;
    }
    inOrderTraversal(root->left, k, element);
    k--;
    if(k == 0){
        element = root->data;
        return;
    }
    inOrderTraversal(root->right, k, element);
}
int findKthSmallest(Node* root, int k){
    int result = -1;
    inOrderTraversal(root, k, result);
    return result;
}
int main(){
    Node* root = nullptr;
    int data, k;
    while(true){
        cin >> data;
        if(data == -1){
            break;
        }
        root = insertNode(root, data);
    }
    cin >> k;
    int kthsmallest = findKthSmallest(root, k);
    cout << "Kth smallest element is: " << kthsmallest << endl;
    return 0;
}