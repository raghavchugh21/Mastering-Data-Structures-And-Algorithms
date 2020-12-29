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
bool isPalindrome(Node *head)
{	
    int n=0;
    Node*temp = head;
    for(n=0;temp!=NULL;n++){
        temp=temp->next;
    }
	for(int i=0;i<n/2;i++){
    Node *temp1 = head, *temp2 = head;
        for(int k=0;k<i;k++){
        temp1=temp1->next;
    	}
        for(int k=0;k<n-i-1;k++){
        temp2=temp2->next;
    	}
        if(temp1->data!=temp2->data)
            return false;
    }
    return true;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}