#include<bits/stdc++.h>
using namespace std;
class PriorityQueue {
    // Declare the data members here
	vector<int> pq;
    
   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
    	pq.push_back(element);
        
        int childIndex = pq.size()-1;
        while(1){
            int parentIndex = (childIndex-1)/2;
            if(parentIndex<0)
                break;
            if(pq[parentIndex]<pq[childIndex]){
                swap(pq[parentIndex],pq[childIndex]);
                childIndex = parentIndex;
            }
            else
                break;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty())
            return INT_MIN;
        
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty())
            return INT_MIN;
        
    	int ans = pq.front();
        swap(pq.front(),pq.back());
        pq.pop_back();
        
        int parentIndex = 0;
        int lchild = 2*parentIndex+1;
		int rchild = 2*parentIndex+2;
            
        while(lchild<pq.size()-1){
            int maxIndex;
            
            if(rchild<pq.size()-1&&pq[lchild]<pq[rchild])
                maxIndex = rchild;
            else
                maxIndex = lchild;
            
			if(pq[parentIndex]<pq[maxIndex]){
                swap(pq[parentIndex],pq[maxIndex]);
                parentIndex = maxIndex;
            }
            else
                break;
            
            lchild = 2*parentIndex+1;
            rchild = 2*parentIndex+2;
        }
        
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
};