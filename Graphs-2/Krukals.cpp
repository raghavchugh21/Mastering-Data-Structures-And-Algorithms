#include<iostream>
#include<algorithm>
using namespace std;

class Edge
{	public:
    int weight;
	int first;
	int second;
};

int get_parent(int current_vertex, vector<int> parent)
{
	if (current_vertex == parent[current_vertex])
	{
		return current_vertex;
	}
	return get_parent(parent[current_vertex], parent);
}

bool sorter(Edge a, Edge b){
    return a.weight<b.weight;
}

int main()
{
    int n,e;
    cin>>n>>e;

    vector<Edge> graph;

    for(int j=0;j<e;j++){
            Edge x;
            cin>>x.first>>x.second>>x.weight;
        	graph.push_back(x);
    }

    sort(graph.begin(),graph.end(),sorter);

    vector<int> parents(n,0);

    for(int i=0;i<n;i++)
        parents[i]=i;

    int count = 0, i = 0;

    while(count<n-1&&i<e){
        if(get_parent(graph[i].first,parents)!=get_parent(graph[i].second,parents)){

            if(graph[i].first<graph[i].second)
            	cout<<graph[i].first<<' '<<graph[i].second<<' '<<graph[i].weight<<endl;
            else
            	cout<<graph[i].second<<' '<<graph[i].first<<' '<<graph[i].weight<<endl;

            parents[get_parent(graph[i].first,parents)] = parents[get_parent(graph[i].second,parents)];
            count++;

        }
        i++;
    }
}