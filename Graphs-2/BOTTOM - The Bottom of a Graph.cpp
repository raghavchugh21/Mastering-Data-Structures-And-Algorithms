#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

void dfs2(int start, vector<int>* edgest, int* visited, unordered_set<int>* component){
	visited[start] = 1;
	component->insert(start);

	for (int i = 0; i < edgest[start].size(); ++i)
	{
		if (visited[edgest[start].at(i)]==0)
		{
			dfs2(edgest[start].at(i), edgest, visited, component);
		}
	}

	return;
}

void dfs(vector<int>* edges, int start, int* visited, stack<int> &s){
	visited[start] = 1;
	for (int i = 0; i < edges[start].size(); ++i)
	{
		if (visited[edges[start].at(i)] == 0)
		{
			dfs(edges, edges[start].at(i), visited, s);
		}
	}

	s.push(start);

	return;
}

unordered_set<unordered_set<int>*>* kosaraju(vector<int>* edges, vector<int>* edgest, int v){

	unordered_set<unordered_set<int>*>* ans = new unordered_set<unordered_set<int>*>();

	stack<int> s;
	int* visited = new int[v];
	for (int i = 0; i < v; ++i)
	{
		visited[i] = 0;
	}

	for (int i = 0; i < v; ++i)
	{
		if (visited[i] == 0)
		{
			dfs(edges, i, visited, s);
		}

	}


	for (int i = 0; i < v; ++i)
	{
		visited[i] = 0;
	}
	while(!s.empty()){
		int t = s.top();
		s.pop();


		if (visited[t] == 0)
		{

			unordered_set<int>* component = new unordered_set<int>();
			dfs2(t, edgest, visited, component);
			ans->insert(component);
		}else{
			continue;
		}
	}

	return ans;

}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	while(1){

		int v, e;
		cin>>v;
		if (v==0)
		{
			break;
		}
		cin>>e;
		vector<int>* edges = new vector<int>[v];
		vector<int>* edgest = new vector<int>[v];

		for (int i = 0; i < e; ++i)
		{
			int a, b;
			cin>>a>>b;

			edges[a-1].push_back(b-1);
			edgest[b-1].push_back(a-1);
		}

		unordered_set<unordered_set<int>*>* components = kosaraju(edges, edgest, v);

		auto it = components->begin();
		vector<int> ans;
		while(it!=components->end())
		{
			int flag = 0;
			auto it2 = (*it)->begin();
			while(it2!=(*it)->end())
			{
				//int i = 0;
				for (int i = 0; i < edges[*it2].size(); ++i)
				{

					if ((*it)->count(edges[*it2].at(i)) == 0)
					{
						flag = 1;
						break;

					}
				}
				if (flag == 1)
				{
					break;
				}
				it2++;
			}
			if (flag == 0)
			{
				it2 = (*it)->begin();
				while(it2!=(*it)->end())
				{
					ans.push_back(*it2 + 1);
					it2++;
				}
			}

			it++;
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); ++i)
		{
			cout<<ans.at(i)<<" ";
		}
	}
	return 0 ;
}