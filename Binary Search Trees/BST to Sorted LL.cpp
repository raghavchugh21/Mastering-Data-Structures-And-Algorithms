#include <iostream>
#include <queue>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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

    Following are the Binary Tree Node class structure and the 
    Node class structure

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

    template <typename T>
    class Node{
        public:
        T data;
        Node<T> *next;
    
        Node(T data) {
            this->data = data;
            this->next = NULL;
        }
    };

***********************************************************/
class constructLL{
    public:
     Node<int>* head ;
    Node<int>* tail ;
    constructLL(){
        this->head=NULL;
        this->tail=NULL;
    }
    constructLL(Node<int>* head,Node<int>* tail){
        this->head = head;
        this->tail = tail;
    }
};

constructLL construct(BinaryTreeNode<int>* root){
    
    if(root==NULL){
        constructLL ans;
        return ans;
    }
    Node<int>* r = new Node<int>(root->data);
    constructLL ans(r,r);
    
    if(root->left==NULL&&root->right==NULL)
        return ans;
    
    constructLL R;
    
    if(root->right)
    R = construct(root->right);
    
    constructLL L;
    
    if(root->left)
    L = construct(root->left);
    
    if(L.head){
        L.tail->next = ans.head;
        ans.head = L.head;
    }
    
    ans.tail->next = R.head;
    
    if(R.tail)
    ans.tail = R.tail;
    
    
    return ans;
    
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    return construct(root).head;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}