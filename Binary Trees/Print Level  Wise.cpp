#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include "solution.h"

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
/**********************************************************

    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/
#include<queue>

void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here3
    queue<BinaryTreeNode<int>*> q;
    if(root==NULL)
        return;
    q.push(root);
    
    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        cout<<front->data<<":";
        if(front->left){
            cout<<"L:"<<front->left->data<<",";
            q.push(front->left);
        }
        else{
            cout<<"L:-1,";
        }
        if(front->right){
            cout<<"R:"<<front->right->data;
            q.push(front->right);
        }
        else{
            cout<<"R:-1";
        }
        cout<<endl;
    }
    
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}