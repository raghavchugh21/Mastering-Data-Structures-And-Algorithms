template <typename T>
class TreeNode {
	TreeNode<T>** children;
	int childCount;
    	int maxChildCount;
	public:
		T data;

		TreeNode(T data) {
			this->data = data;
			childCount = 0;
			children = new TreeNode<T>*[10];
		   	maxChildCount = 10;
        }

		int numChildren() {
			return childCount;
		}

		void addChild(TreeNode<T>* child) {
			children[childCount] = child;
			childCount++;
            if(childCount == maxChildCount) {
	            TreeNode<T>** childrenNew = new TreeNode<T>*[2*maxChildCount];
        	    for(int i = 0; i < maxChildCount; i++) {
	                childrenNew[i] = children[i];
        	     }
	        	 maxChildCount *= 2;
        	        children = childrenNew;
	        }
		}

		TreeNode<T>* getChild(int index) {
			return children[index];
		}

		void setChild(int index, TreeNode<T>* child) {
			children[index] = child;
		}
};

template <typename T>
class Queue {
	T* data;
	int capacity;
	int nextIndex;
	int firstIndex;
	int length;

	public:
		Queue() {
			capacity = 10;
			data = new T[capacity];
			length = 0;
			nextIndex = 0;
			firstIndex = -1;
		}

		int size() {
			return length;
		}

		bool isEmpty() {
			return length == 0;
		}

		T front() {
			if (length == 0) {
				return 0;
			}
			return data[firstIndex];
		}

		T dequeue() {
			if (length == 0) {
				return 0;
			}

			T output = data[firstIndex];
			length--;
			firstIndex = (firstIndex + 1)%capacity;
			if (length == 0) {
				firstIndex = -1;
				nextIndex = 0;
			}
			return output;
		}

		void enqueue(T element) {
			if (length == capacity) {
				T* temp = data;
				capacity = 2* capacity;
				data = new T[capacity];
				int k = 0;
				for (int i = firstIndex; i < length; i++) {
					data[k] = temp[i];
					k++;
				}
				for (int i = 0; i < firstIndex; i++) {
					data[k] = temp[i];
					k++;
				}
				delete [] temp;
				firstIndex = 0;
				nextIndex = length;
			}
			data[nextIndex] = element;
			length++;
			nextIndex = (nextIndex + 1) % capacity;
			if (firstIndex == -1) {
				firstIndex = 0;
			}
		}

		~Queue() {
			delete [] data;
		}


};

#include <iostream>
#include <climits>
using namespace std;
#include "solution.h"

TreeNode<int>* takeInputLevelWise() {
	Queue<TreeNode<int>*> q;
	int rootData;
	
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	q.enqueue(root);
	while (!q.isEmpty()) {
		TreeNode<int>* frontNode = q.dequeue();

		int numChildren;
		cin >> numChildren;
		for (int i = 0; i < numChildren; i++) {

			int childData;
			cin >> childData;
			TreeNode<int>* childNode = new TreeNode<int>(childData);
			q.enqueue(childNode);
			frontNode->addChild(childNode);
		}
	}
	return root;
}

// Following is the given Tree node structure
/**************

class TreeNode {
	TreeNode<T>** children;
	int childCount;

	public:
	T data;

	TreeNode(T data);	// Constructor
	int numChildren();
	void addChild(TreeNode<T>* child);
	TreeNode<T>* getChild(int index);
	void setChild(int index, TreeNode<T>* child);
};

***************/
TreeNode <int>* Largest(TreeNode<int> *root){
    
    int max = root->data;
    TreeNode <int>* ans = root;
    
    for(int i=0;i<root->numChildren();i++){
        TreeNode <int>* X = Largest(root->getChild(i));
        if(X->data>max){
			max = X->data;
            ans = X;
        }
    }
    
    return ans;
}

TreeNode<int>* nextSmallest(TreeNode<int> *root, int K){
    
    int min = INT_MAX;
    TreeNode <int>* ans = NULL;
    
    if(K!=root->data){
    	min = K-root->data;
    	ans = root;
    }
    
    for(int i=0;i<root->numChildren();i++){
        TreeNode <int>* X = nextSmallest(root->getChild(i),K);
        if(X!=NULL&&K!=X->data)
        if(K-X->data<min){
			min = K-X->data;
            ans = X; 
        }
    }
    
    return ans;
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    
	TreeNode <int>* max = Largest(root);
    
    return nextSmallest(root,max->data);
    
}



int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL)
    	cout << INT_MIN << endl;
    else
	cout << ans -> data << endl;
}
