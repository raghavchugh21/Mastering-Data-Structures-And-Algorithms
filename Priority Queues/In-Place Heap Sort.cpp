#include <iostream>
#include "solution.h"

using namespace std;

#include<bits/stdc++.h>
using namespace std;

void buildheap(int pq[],int n){
    if(n==1||n==0)
        return;
    int childIndex = n-1;
    while(1){
        int parentIndex = (childIndex-1)/2;
        if(parentIndex<0)
            break;
        if(pq[parentIndex]>pq[childIndex]){
            swap(pq[parentIndex],pq[childIndex]);
            childIndex = parentIndex;
        }
        else
            break;
    }
}

void removemax(int pq[],int n){
    
        if(n==0||n==1)
            return;
    
        swap(pq[0],pq[n-1]);
        
        int parentIndex = 0;
        int lchild = 2*parentIndex+1;
        int rchild = 2*parentIndex+2;
            
        while(lchild<n-1){
            int maxIndex;
            
            if(rchild<n-1&&pq[lchild]>pq[rchild])
                maxIndex = rchild;
            else
                maxIndex = lchild;
            
            if(pq[parentIndex]>pq[maxIndex]){
                swap(pq[parentIndex],pq[maxIndex]);
                parentIndex = maxIndex;
            }
            else
                break;
            
            lchild = 2*parentIndex+1;
            rchild = 2*parentIndex+2;
        }
        
}

void heapSort(int arr[], int n) {
    // Write your code
    for(int i=1;i<=n;i++)
        buildheap(arr,i);
    
    
    for(int i=0;i<n;i++)
        removemax(arr,n-i);

}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}