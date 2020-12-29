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
Node *skipMdeleteN(Node *head, int M, int N)
{
    if(head==NULL||N==0)
        return head;
    
    if(M==0)
        return NULL;
    
 	Node*temp = head;
    int count = 0;
    
    while(count<M-1&&temp!=NULL){
        temp = temp->next;
        count++;
    }
    
    Node*n1 = temp;
    count=0;
    
    while(count<=N&&temp!=NULL){
        temp = temp->next;
        count++;
    }
    
    Node *n2 = temp;
    n2 = skipMdeleteN(n2,M,N);    
    
    if(n1!=NULL){
        if(n2!=NULL){
    		n1->next = n2;            
        }
        else{
            n1->next = NULL;
        }
    }
    
    return head;
    
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}