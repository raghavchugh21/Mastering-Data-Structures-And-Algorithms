#include <iostream>
#include <limits.h>
using namespace std;

int findMin(int *time ,bool* visited,int n)
{
    int minV=-1;

    for(int i=1;i<=n;i++)
    {
        if(!visited[i] && (minV==-1 || time[minV]>time[i]))
            minV=i;
    }
    return minV;
}


void printarr(int *a,int n){
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void dijkt(int **edges,int n,int* period, int* time,int src,int dest){

    bool *visited=new bool[n+1];
    for(int i=1;i<=n;i++)visited[i]=false;

    time[src]=0;
    for(int i=1;i<=n;i++)
    {
        int minV=findMin(time,visited,n);
        visited[minV]=true;

        for(int j=1;j<=n;j++)
        {
            if(edges[minV][j] && !visited[j])
            {
                if(j!=dest)
                {
                    int t_pass=time[minV]+edges[minV][j];
                    int waitime;
                    if(t_pass%period[j]==0)
                        waitime=0;
                    else
                        waitime=period[j]-t_pass%period[j];
                    int t=t_pass+waitime;

                    if(t<time[j])
                        time[j]=t;
                }
                else
                {
                    int t=time[minV]+edges[minV][j];
                    if(t<time[j])
                        time[j]=t;
                }
            }
        }
    }
    delete visited;


}

int main() {
	int n, m;
	cin >> n >> m;

    int **edges=new int*[n+1];
    for(int i=1;i<=n;i++)
    {
        edges[i]=new int[n+1];
        for(int j=1;j<=n;j++)
            edges[i][j]=0;
    }

    int* period=new int[n+1];
    int* time=new int[n+1];
    for(int i=1;i<=n;i++)
    {
        time[i]=INT_MAX;
        cin>>period[i];
    }
    time[0]=INT_MAX;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        edges[x][y]=w;
        edges[y][x]=w;
    }
    int src,dest;
    cin>>src>>dest;

    dijkt(edges,n,period,time,src,dest);

    int ans=time[dest];
    cout<<ans<<endl;

    //printarr(time,n);
    delete period;
    delete time;
    for(int i=1;i<=n;i++) delete edges[i];
    delete edges;

}