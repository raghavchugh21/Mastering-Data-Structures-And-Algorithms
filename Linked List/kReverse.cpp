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

Node* reverse(Node *head, Node *tail){
    
    if(head == tail)
        return head;
    
    Node *a = head->next;
    Node *newhead = reverse(head->next,tail);
    a->next = head;
    
    return newhead;
}

Node *kReverse(Node *head, int k){
    
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    Node *h1 = head;
    Node *t1 = head;
    int count = 0;
    
    while(count<k-1&&t1->next!=NULL){
        t1=t1->next;
        count++;
    }
	
    Node *h2 = t1->next;
    head = reverse(h1,t1);
    h1->next = kReverse(h2,k);
    
    return head;
    
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}