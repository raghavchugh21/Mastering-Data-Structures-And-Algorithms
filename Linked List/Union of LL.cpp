#include <iostream>
using namespace std;

template <typename T>
class ListNode {
    public:
    T data;
    ListNode<T> *next;
    ListNode<T>(T data)
    {
        this -> data=data;
        next = NULL;
    }
};

#include "solution.h"

 ListNode<int>* createlist()
	{
	    ListNode<int> *head=NULL;
		ListNode<int> *rear=NULL;
		int data;
		cin>>data;
		while(data!=-1)
		{
			ListNode<int> *newnode=new ListNode<int>(data);
			if(head==NULL)
			{
				head=newnode;
				rear=head;
			}
			else
			{
				rear->next=newnode;
				rear=rear->next;
			}
			cin>>data;
		}
		return head;
	}

    void print(ListNode<int> * head)
	{
		while(head!=NULL)
		{
			cout<<head->data<<endl;
			head=head->next;
		}
	}

#include<unordered_map>
using namespace std;

ListNode<int>* SortedMerge(ListNode<int>* a, ListNode<int>* b) 
{ 
    ListNode<int>* result = NULL; 
  
    /* Base cases */
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    /* Pick either a or b, and recur */
    if (a->data <= b->data) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
} 
  
/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,  
    and return the two lists using the reference parameters.  
    If the length is odd, the extra node should go in the front list.  
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(ListNode<int>* source, 
                    ListNode<int>** frontRef, ListNode<int>** backRef) 
{ 
    ListNode<int>* fast; 
    ListNode<int>* slow; 
    slow = source; 
    fast = source->next; 
  
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
  
    /* 'slow' is before the midpoint in the list, so split it in two  
    at that point. */
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 

void MergeSort(ListNode<int>** headRef) 
{ 
    ListNode<int>* head = *headRef; 
    ListNode<int>* a; 
    ListNode<int>* b; 
  
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 
  
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b); 
  
    /* Recursively sort the sublists */
    MergeSort(&a); 
    MergeSort(&b); 
  
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b); 
} 

   ListNode<int> *unionOf2LL(ListNode<int> *head1,ListNode<int> *head2)
	{
		ListNode<int> *tail1 = head1;
       unordered_map<int,int> inList1;
       	
        while(tail1->next!=NULL){
            inList1[tail1->data]++;
    	    tail1 = tail1->next;
        }
       
        inList1[tail1->data]++;
        
       	while(head2!=NULL){
            
            if(inList1[head2->data]!=0){
                inList1[head2->data]--;
               head2 = head2->next;
                continue; 
            }
            
            tail1->next = head2;
            tail1 = tail1->next;
            head2 = head2->next;
        }
      	
       	tail1->next = NULL;
       MergeSort(&head1);
        return head1;
	}


int main()
{
   ListNode<int> *head1=createlist();
   ListNode<int> *head,*head2=createlist();
   head=unionOf2LL(head1,head2);
   print(head);
}
