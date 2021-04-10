
int dfs(vector<vector<int>> &cake,int i, int j, int n, vector<vector<bool>> &visited){

    if(visited[i][j]){
        return 0;
    }

    visited[i][j] = true;

    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    int ans = 0;

    for(int k=0;k<4;k++){
        int x = i+dx[k];
        int y = j+dy[k];
        if(x<n&&y<n&&x>=0&&y>=0&&cake[x][y]==1)
    		ans += dfs(cake,x,y,n,visited);
    }

    return 1+ans;

}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(cake[i][j]==1&&!visited[i][j])
                ans = max(ans,dfs(cake,i,j,n,visited));

        }
    }

    return ans;
}