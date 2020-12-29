//Write a function AlternatingSplit() that takes one list and divides up its nodes to make two smaller lists a and b. 
//The sublists should be made from alternating elements in the original list.
//nodes should be in the reverse order of which they occurred in the source list
#include<iostream>
using namespace std;

template <typename T>
class Node {
	public:
	T data;
	Node* next;

	Node(T data) {
		next = NULL;
		//(*this).data = data;
		this->data = data;
	}

	~Node() {
		if (next != NULL) {
			delete next;
		}
	}
};
#include "solution.h"
Node<int>* takeLLInput() {
    int data;
    cin>>data;
    Node<int>* head=NULL,*tail=NULL;
    while(data!=-1){
        Node<int> *newnode=new Node<int>(data);
        if(head==NULL) {
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

#include<iostream>
using namespace std;

void printalt(Node<int> *head){
    
    if(head==NULL)
        return;
    if(head->next!=NULL)
    printalt(head->next->next);
    
    cout<<head->data<<' ';
    
}
void AlternatingSplit(Node<int>* head){
    
    if(head==NULL)
        return;
    
    printalt(head);
    cout<<endl;
    printalt(head->next);

}


int main()
{ 
	Node<int>* head=takeLLInput();

	AlternatingSplit(head);
	
}
