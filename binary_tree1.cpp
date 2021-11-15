#include <iostream>
#include <vector>
#include <cmath>

#define ll long long
#define ull unsigned long long long

using namespace std;


struct Node{
    int value;
    Node *left, *right;

    Node() {
        left = nullptr;
        right = nullptr;
    }

    Node(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }
};


void preorder(Node *root){
    
    if(root == nullptr)
        return;
    
    cout << root->value << " ";

    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root){
    
    if(root == nullptr)
        return;
    

    preorder(root->left);

    cout << root->value << " ";
    
    preorder(root->right);
}

void postorder(Node *root){
    
    if(root == nullptr)
        return;
    
    preorder(root->left);
    preorder(root->right);

    cout << root->value << " ";
    
}


int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left->left = new Node(6);
    root->right->right->left = new Node(7);

    cout << "Pre-order traversal of the given tree is as follows : \n";
    preorder(root);

    cout << "\n\nIn-order traversal of the given tree is as follows : \n";
    inorder(root);

    cout << "\n\nPost-order traversal of the given tree is as follows : \n";
    postorder(root);

    return 0;
}