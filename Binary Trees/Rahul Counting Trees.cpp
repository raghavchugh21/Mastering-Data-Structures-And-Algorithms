#include <bits/stdc++.h>
#include <iostream>
#define ll long long int
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
ll haveAncestorSum(BinaryTreeNode<ll>*root, ll K){
	
    vector<ll> ans;
    queue<BinaryTreeNode<ll>*> q;
    
    if(root==NULL)
        return 0;
    if(root->left)
    	q.push(root->left);
    if(root->right)
    	q.push(root->right);
    
    while(!q.empty()){
		BinaryTreeNode<ll>*front = q.front();
        ans.push_back(front->data);
        q.pop();
        if(front->left)
        q.push(front->left);
        if(front->right)
        q.push(front->right);
    }
    
    ll c=0;
    for(ll j=0;j<ans.size();j++){
        for(ll k=0;k<ans.size();k++){
            if(j!=k)
                if(ans[j]+ans[k]+root->data>=K)
                    c++;
        }
    }
    return c;
}
ll countingTrees(BinaryTreeNode<ll>* root, ll K){
    
	ll ans = haveAncestorSum(root,K);
    
    if(root==NULL)
        return ans;
    
    if(root->left)
        ans+=countingTrees(root->left,K);
    
    if(root->right)
        ans+=countingTrees(root->right,K);
    
    return ans;
}
int main() {
    /* Write Your Code Here
    * You have to take input and prll the output yourself
    */
    ll N,K;
    cin>>N>>K;
    BinaryTreeNode<ll>** a = new BinaryTreeNode<ll>*[N];
    for(ll i=0;i<N;i++){
        ll data;
        cin>>data;
        a[i] = new BinaryTreeNode<ll>(data);
    }
    
    for(ll i=1;i<N;i++){
    	ll par;
        cin>>par;
        if(!a[par-1]->left)
            a[par-1]->left = a[i];
        else if(!a[par-1]->right)
            a[par-1]->right = a[i];
    }
    cout<<countingTrees(a[0],K)/2;
    return 0;
}
