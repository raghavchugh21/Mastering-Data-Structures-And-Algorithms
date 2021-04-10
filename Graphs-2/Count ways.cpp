#include<bits/stdc++.h>
using namespace std;
int dp[200005],MOD=1000000007;
vector<vector<int> > adjacent;

int recurse(int s)
{
    if(dp[s]!=-1)
        return dp[s];
    int ans=1;
    for(int i=0;i<adjacent[s].size();i++)
        ans=(recurse(adjacent[s][i])+ans)%MOD;
    return dp[s]=ans;
}

int solve(int n,int m,int s,vector<vector<int> > graph)
{
    adjacent=graph;
    for(int i=1;i<=n;i++)
        dp[i]=-1;
    return recurse(s);
}
vector<vector<int> > graph;
int main()
{
    int n,m,s,t,p;
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        vector<int> v;
        graph.push_back(v);
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    cin>>s;
    cout<<solve(n,m,s,graph)<<endl;
    return 0;
}