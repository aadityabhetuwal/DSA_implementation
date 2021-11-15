#include <iostream>
#include <vector>
#include <cmath>

#define ll long long
#define ull unsigned long long long

using namespace std;

template <typename T>
struct TreeNode{
    T value;
    TreeNode *left, *right;

    TreeNode() {
        left = nullptr;
        right = nullptr;
    }

    TreeNode(T data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
TreeNode<T>* create_tree_from_array(T *arr, TreeNode<T> *rootNode, int i, int n){
    
    if(i < n){
        TreeNode<T> *newNode = new TreeNode<T>(arr[i]);
        rootNode = newNode;
        
        rootNode->left = create_tree_from_array<T>(arr, rootNode->left, 2 * i + 1, n);

        rootNode->right = create_tree_from_array<T>(arr, rootNode->right, 2 * i + 2, n);

    }
    return rootNode;
}

template <typename T>
void printData(TreeNode<T> *currNode){
    cout << currNode.value;
}

template <typename T>
void preorder_traversal(TreeNode<T> *currNode){
    
    if(currNode == nullptr)
        return;
    
    cout << currNode->value << " ";

    preorder_traversal<int>(currNode->left);
    preorder_traversal<int>(currNode->right);
}


template <typename T>
void inorder_traversal(TreeNode<T> *currNode){
    
    if(currNode == nullptr)
        return;
    
    inorder_traversal<int>(currNode->left);
    
    cout << currNode->value << " ";

    inorder_traversal<int>(currNode->right);
}


template <typename T>
void postorder_traversal(TreeNode<T> *currNode){
    
    if(currNode == nullptr)
        return;
    
    postorder_traversal<int>(currNode->left);
    postorder_traversal<int>(currNode->right);
    
    cout << currNode->value << " ";

}



int main(){
    int n = 15;

    int arr[n] = {25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 90};

    TreeNode<int> *rootNode = create_tree_from_array<int>(arr, rootNode, 0, n);
    // TreeNode<int> *tmpNode = rootNode;

    cout << "Pre-order traversal of the given tree is as follows : \n";
    preorder_traversal<int>(rootNode);

    cout << "\n\nIn-order traversal of the given tree is as follows : \n";
    inorder_traversal<int>(rootNode);

    cout << "\n\nPost-order traversal of the given tree is as follows : \n";
    postorder_traversal<int>(rootNode);

    return 0;
}