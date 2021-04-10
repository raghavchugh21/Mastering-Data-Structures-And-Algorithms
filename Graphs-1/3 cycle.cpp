#include<bits/stdc++.h>
using namespace std;



int main()
{

    int n, e;
    cin >> n >> e;
    bool graph [n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = false;

        }
    }

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x][y] = true;
        graph[y][x] = true;
    }

    int count = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==i)
                continue;
            for(int k=0;k<n;k++){
                if(k==i||k==j)
                    continue;
                if(graph[i][j]&&graph[j][k]&&graph[k][i])
                    count++;
            }
        }
    }

    cout<<count/6;
}