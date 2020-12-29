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

#include<iostream>
using namespace std;
Node *swapNodes(Node *head, int i, int j)
{	
    Node *nodei = head, *nodej = head;
    if(j<i)
        swap(i,j);
 	
	for(int k=0;k<i-1;k++){
        nodei = nodei->next;
    }
	
 	Node *iprev = nodei;
    nodei = nodei->next;
	
 	for(int k=0;k<j-1;k++){
        nodej = nodej->next;
    }
 	
    Node *jprev = nodej;
 	nodej = nodej->next;
    Node *inext = nodei->next;
    
    if(i==j){
		return head;
    }
    else if(j-i==1){
        iprev->next = nodej;
    	nodei->next = nodej->next;
        nodej->next = nodei;  	
    }
    else if(i==0){
        nodei->next = nodej->next;
        nodej->next = inext;
        jprev->next = nodei;
        head = nodej;
    }
    else{
        iprev->next = nodej;
        jprev->next = nodei;
        nodei->next = nodej->next;
        nodej->next = inext;
    }
 	
    return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}