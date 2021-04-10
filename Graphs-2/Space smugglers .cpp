
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define max 100010
#define INF 10000000000
#define mp make_pair
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > pq;
vector<pii> g[max],gt[max];
void debug(vector<ll> a,int n)
{
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
}
int main()
{
	ll n,m,s,t;
	cin>>n>>m>>s>>t;
	for(ll i=1;i<=m;i++)
	{
		ll a,b,wt;
		cin>>a>>b>>wt;
		g[a].push_back(mp(b,wt));
		gt[b].push_back(mp(a,wt));
	}
	vector<ll> dist1(max,INF),dist2(max,INF),dist3(max,INF),dist4(max,INF);
	dist1[s]=0;
	pq.push(mp(0,s));
	while(!pq.empty())
	{
		ll u,v,wet;
		pii pp=pq.top();
		pq.pop();
		u=pp.second;
		for(ll j=0;j<g[u].size();j++)
		{
			pii pp1=g[u][j];
			v=pp1.first;
			wet=pp1.second;
			if(dist1[v]>dist1[u]+wet)
			{
				dist1[v]=dist1[u]+wet;
				pq.push(mp(dist1[v],v));
			}
		}
	}
	// debug(dist1,n);
	dist2[s]=0;
	pq.push(mp(0,s));
	while(!pq.empty())
	{
		ll u,v,wet;
		pii pp=pq.top();
		pq.pop();
		u=pp.second;
		for(ll j=0;j<gt[u].size();j++)
		{
			pii pp1=gt[u][j];
			v=pp1.first;
			wet=pp1.second;
			if(dist2[v]>dist2[u]+wet)
			{
				dist2[v]=dist2[u]+wet;
				pq.push(mp(dist2[v],v));
			}
		}
	}
	// debug(dist2,n);
	dist3[t]=0;
	pq.push(mp(0,t));
	while(!pq.empty())
	{
		ll u,v,wet;
		pii pp=pq.top();
		pq.pop();
		u=pp.second;
		for(ll j=0;j<g[u].size();j++)
		{
			pii pp1=g[u][j];
			v=pp1.first;
			wet=pp1.second;
			if(dist3[v]>dist3[u]+wet)
			{
				dist3[v]=dist3[u]+wet;
				pq.push(mp(dist3[v],v));
			}
		}
	}
	// debug(dist3,n);
	dist4[t]=0;
	pq.push(mp(0,t));
	while(!pq.empty())
	{
		ll u,v,wet;
		pii pp=pq.top();
		pq.pop();
		u=pp.second;
		for(ll j=0;j<gt[u].size();j++)
		{
			pii pp1=gt[u][j];
			v=pp1.first;
			wet=pp1.second;
			if(dist4[v]>dist4[u]+wet)
			{
				dist4[v]=dist4[u]+wet;
				pq.push(mp(dist4[v],v));
			}
		}
	}
	// debug(dist4,n);
	ll ans=INF;
	for(ll i=1;i<=n;i++)
	{
		if(dist1[i]!=INF&&dist2[i]!=INF&&dist3[i]!=INF&&dist4[i]!=INF&&i!=s&&i!=t)
		{
			ans=min(ans,dist1[i]+dist2[i]+dist3[i]+dist4[i]);
		}
	}
	if(ans==INF)
		cout<<"-1\n";
	else
		cout<<ans<<endl;
}