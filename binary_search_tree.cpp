#include <iostream>
#include <vector>
#include <cmath>

#define ll long long
#define ull unsigned long long long

using namespace std;

const int garbage = -1e9;

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
TreeNode<T>* insert_node(TreeNode<T> *root, T elem){

    if(root == nullptr){
        root = new TreeNode<T>(elem);
        // root->value = elem;
        return root;
    }

    if(elem< root->value){
        root->left =  insert_node(root->left, elem);
    
    }else{
        root->right = insert_node(root->right, elem);
    }

    return root;
}

// returns the root if elements exists in binary search tree, else returns nullptr
template <typename T>
TreeNode<T>* find_elem(TreeNode<T> *root, T elem){

    if(root == nullptr){
        return nullptr;
    }

    if(elem == root->value)
        return root;
    else if(elem < root->value)
        return find_elem(root->left, elem);
    return find_elem(root->right, elem);
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
TreeNode<T>* get_min_elem(TreeNode<T> *root){
    
    if(root->left == nullptr)
        return root;
    
    return get_min_elem(root->left);
}

template <typename T>
TreeNode<T>* get_max_elem(TreeNode<T> *root){
    
    if(root->right == nullptr)
        return root;
    
    return get_max_elem(root->right);
}

template <typename T>
TreeNode<T>* delete_from_bst(TreeNode<T> *node, T elem){

    if(node == nullptr){
        return nullptr;
    }

    if(elem < node->value)
        node->left = delete_from_bst(node->left, elem);
    else if(elem > node->value)
        node->right = delete_from_bst(node->right, elem);

    else{
        TreeNode<T> *tmp;

        if(node->left == nullptr && node->right == nullptr){
            delete node;
            return nullptr;

        }else if(node->left == nullptr){
            tmp = node->right;
            delete node;
            return tmp;

        }else if(node->right == nullptr){
            tmp = node->left;
            delete node;
            return tmp;

        }

        TreeNode<T>* max_node = get_max_elem(node->left);
        node->value = max_node->value;

        node->left = delete_from_bst(node->left, max_node->value);
        
    }
    return node;
}

int main(){

    TreeNode<int> *root = nullptr, *tmp;
    vector<int> ve = {20, 10, 40, 6, 15, 30, 2, 8, 25, 35};

    for(int i = 0; i < ve.size(); i++){
        root = insert_node(root, ve[i]);
    }

    cout << "The Binary search tree(BST) elements originally are : \n\n";
    inorder_traversal(root);

    cout << "\nMinimum element is = " << get_min_elem(root)->value << '\n';
    cout << "Maximum element is = " << get_max_elem(root)->value << '\n';
    inorder_traversal(root);
    cout << '\n';

    delete_from_bst(root, 10);
    cout << "Deleting 10 from BST i.e. a 2 degree node. Now the BST becomes : \n";
    inorder_traversal(root);
    cout << '\n';

    delete_from_bst(root, 35);
    cout << "Deleting 35 from BST i.e. a 0 degree node. Now the BST becomes : \n";
    inorder_traversal(root);
    cout << '\n';

    delete_from_bst(root, 40);
    cout << "Deleting 40 from BST i.e. a 1 degree node. Now the BST becomes : \n";
    inorder_traversal(root);
    cout << '\n';

    return 0;
}
