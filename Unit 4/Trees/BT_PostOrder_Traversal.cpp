
 /* Imagine you are given a series of integers that represent the data to be inserted into a 
    binary tree using level-order traversal. Construct the binary tree with these integers and perform 
    a post-order traversal. After printing the post-order traversal, calculate and print the sum 
    of all odd values in the tree. */

// Data Structure used -> Linked List

#include <iostream>
#include <queue>
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
Node* levelOrderInsert(Node* root, int data){
    Node* newNode = new Node(data);
    if(root == nullptr){
        return newNode;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        if(current->left == nullptr){
            current->left = newNode;
            break;
        } else{
            q.push(current->left);
        }


        if(current->right == nullptr){
            current->right = newNode;
            break;
        } else{
            q.push(current->right);
        }
    }

    return root;
}
void printPostOrder(Node* node){
    if(node == nullptr){
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout << node->data << " ";
}
int main(){
    int num, data;
    cin >>num;
    Node* root = nullptr;
    while(num-- > 0){
        cin >> data;
        root = levelOrderInsert(root, data);
    }
    cout << "Post Order Traversal: ";
    printPostOrder(root);
    cout << endl;
    return 0;
}