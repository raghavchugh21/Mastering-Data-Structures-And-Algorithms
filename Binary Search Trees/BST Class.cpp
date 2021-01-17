#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

#include "solution.h"
#include<queue>

class BST {
    // Define the data members
    BinaryTreeNode<int>*root;
   public:
    BST() { 
        this->root = NULL;
    }

    /*----------------- Public Functions of BST -----------------*/
    private:
    int minimum(BinaryTreeNode<int>*root){
        if(root==NULL)
            return 0;
        int ans = root->data;
        if(root->right)
            ans = min(ans,minimum(root->right));
        if(root->left)
            ans = min(ans,minimum(root->left));
        return ans;
    }
    BinaryTreeNode<int>* remove(int data,BinaryTreeNode<int>*root) {
        
        if(root==NULL)
            return root;
        
        if(root->data==data){
            if(root->left&&!root->right){
                root = root->left;
            }
            else if(!root->left&&root->right){
                root = root->right;
            }
            else if(root->left&&root->right){
                root->data = minimum(root->right);
                root->right = remove(root->data,root->right);
            }
            else if(!root->left&&!root->right){
                delete root;
                root=NULL;
            }
        }
        
        else if(root->data>data)
            root->left = remove(data,root->left);
        
        
        else if(root->data<data)
            root->right = remove(data,root->right);
            
        return root;
    }
    
    void print(BinaryTreeNode<int>*root){
        if(root==NULL)
            return;
        
        cout<<root->data<<':';
        if(root->left){
            cout<<"L:"<<root->left->data<<',';
        }
        if(root->right){
            cout<<"R:"<<root->right->data;
        }
        cout<<endl;
        
        print(root->left);
        print(root->right);
    }
    
    BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int>*root){
        if(root==NULL){
            root = new BinaryTreeNode<int>(data);
            return root;
        }
        if(root->data<data){
            root->right = insert(data,root->right);
            return root;
        }
        if(root->data>=data){
            root->left = insert(data,root->left);
            return root;
        }
    }
    
    bool search(int data, BinaryTreeNode<int>* root){
        if(root==NULL)
            return false;
        if(root->data==data)
            return true;
        else if(root->data<data)
            return search(data,root->right);
        else if(root->data>data)
            return search(data,root->left);
        return false;
    }
    
    public:
    
    void remove(int data) { 
        // Implement the remove() function 
        this->root = remove(data,this->root);
    }

    void print() { 
        // Implement the print() function
        print(this->root);
    }

    void insert(int data) { 
        // Implement the insert() function 
        this->root = insert(data,this->root);
    }

    bool search(int data) {
        // Implement the search() function
        search(data,this->root);
    }

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}