#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        int ans = pq.front();
    	swap(pq.front(),pq.back());
        
        pq.pop_back();
        
        int parent = 0;
        
        while(1){
            int lchild = 2*parent+1;
            int rchild = 2*parent+2;
            
            if(lchild>=pq.size())
                break;
            
              if(rchild>=pq.size()||pq[lchild]<pq[rchild]){
                  if(pq[parent]>pq[lchild]){
                      swap(pq[parent],pq[lchild]);
                      parent = lchild;
                  }
                  else
                  	break;
              }
              else{
                  if(pq[parent]>pq[rchild]){
                      swap(pq[parent],pq[rchild]);
                      parent = rchild;
                  }
                  else
                  	break;
              }
        }
        return ans;
    }
};