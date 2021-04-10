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
                if(weights[minIdx] + edges[minIdx][p]<weights[p]){
                    weights[p] = weights[minIdx] + edges[minIdx][p];
                }
            }
        }

        visited[minIdx] = true;

    }

    for(int i=0;i<n;i++){
        cout<<i<<' '<<weights[i]<<endl;
    }
}