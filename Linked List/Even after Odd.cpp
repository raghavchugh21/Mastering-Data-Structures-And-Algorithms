#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
#include "solution.h"

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
Node *evenAfterOdd(Node *head)
{
    Node *even = head;

    while(even!=NULL&&even->data%2!=0)
        even = even->next;
	
    Node *evenList;
    
    if(even!=NULL){
    	evenList = new Node(even->data);
    	even = even->next;
    }
    else{
        evenList = NULL;
    }
    
    Node *evenTail = evenList;
    while(even!=NULL){
        if(even->data%2 == 0){
            Node *temp = new Node(even->data);
    		evenTail->next = temp;
            evenTail = evenTail->next;
            even=even->next;
        }
        else
            even = even->next;
    } 
    
    Node *odd = head;
    
    while(odd!=NULL&&odd->data%2==0)
        odd = odd->next;
    
    Node *oddList;
    
    if(odd!=NULL){
    	oddList = new Node(odd->data);
        odd = odd->next;
    }
    else{
        oddList = NULL;
    }
    
    Node *oddTail = oddList;
    
    while(odd!=NULL){
        if(odd->data%2 != 0){
            Node *temp = new Node(odd->data);
    		oddTail->next = temp;
            oddTail = oddTail->next;
            odd = odd->next;
        }
        else
            odd = odd->next;
    }
    
    if(oddList == NULL){
        return evenList;
    }
    else{
    	oddTail->next = evenList;
    	return oddList;
    }
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}