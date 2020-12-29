//Move last element to front of a given Linked List
#include<iostream>
using namespace std;

template <typename T>
class Node {
	public:
	T data;
	Node* next;

	Node(T data) {
		next = NULL;
		this->data = data;
	}

	~Node() {
		if (next != NULL) {
			delete next;
		}
	}
};

#include"solution.h"


Node<int>* takeLLInput() {
    int data;
    cin>>data;
    Node<int>* head=NULL,*tail=NULL;
    while(data!=-1){
        Node<int> *newnode=new Node<int>(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}

void printLL(Node<int>*  head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

Node<int>* moveToFront(Node<int> *head_ref) {
    if(head_ref == NULL||head_ref->next == NULL)
        return head_ref;
	// Write your code here
    Node<int>* n1 = head_ref;
    
    while(n1->next->next!=NULL)
    	n1=n1->next;
    Node<int> *n2 = n1->next;
    if(n1==head_ref){
        n2->next = head_ref;
        head_ref->next = NULL;
        head_ref = n2;
    }
    else{
        n2 = n1->next;
        n1->next=NULL;
        n2->next=head_ref;
        head_ref=n2;
    }
	return head_ref;
}


int main() {

	Node<int>* head = takeLLInput();
	head = moveToFront(head);
	printLL(head);
	delete head;
}
