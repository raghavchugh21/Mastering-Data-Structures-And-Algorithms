#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int main()
{
	int n, e;
	cin >> n >> e;
	int** edges = new int* [n];
	for (int i = 0; i < n; i++)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			edges[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++)
	{
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}

    vector<bool> visited(n,false);
	vector<int> weights(n,INT_MAX);
    vector<int> parents(n,-1);
    weights[0] = 0;

    for(int k=0;k<n-1;k++){

        int minIdx=INT_MAX;
        int min=INT_MAX;

        for(int i=0;i<n;i++){
            if(!visited[i]&&weights[i]<min){
                min = weights[i];
            	minIdx = i;
        	}
        }

        for(int p=0;p<n;p++){
            if(edges[minIdx][p]&&!visited[p]){
                if(edges[minIdx][p]<weights[p]){
                    weights[p] = edges[minIdx][p];
                	parents[p] = minIdx;
                }
            }
        }

        visited[minIdx] = true;

    }

    for(int i=1;i<n;i++){
        if(i<parents[i])
            cout<<i<<' '<<parents[i]<<' '<<edges[i][parents[i]]<<endl;
        else
            cout<<parents[i]<<' '<<i<<' '<<edges[i][parents[i]]<<endl;
    }

}