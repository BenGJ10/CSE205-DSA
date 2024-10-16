#include <iostream>
#include <queue>
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
Node* levelOrderInsertion(Node* root, int d){
    Node* newNode = new Node(d);
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

void preOrderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
int main(){
    int num, data;
    cin >> num;
    Node* root = nullptr;

    while(num-- > 0){
        cin >> data;
        root = levelOrderInsertion(root, data);
    }
    preOrderTraversal(root);
    cout << endl;
    return 0;
}