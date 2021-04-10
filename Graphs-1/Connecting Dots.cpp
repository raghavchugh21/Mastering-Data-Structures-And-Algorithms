#include<vector>

bool checkCycle(vector<vector<char>> &board,int sx,int sy,int x, int y, int n, int m, int cycleLength, vector<vector<bool>> &visited){

    if(x>=n||y>=m||x<0||y<0)
        return false;

    int dx[] = {0,1,0,-1,1,1,-1,-1};
    int dy[] = {1,0,-1,0,1,-1,1,-1};

    visited[x][y] = true;

    if(x==sx&&y==sy&&cycleLength>=3)
        return true;

    return false;
}

bool hasCycle(vector<vector<char>> &board, int n, int m){
	// Write your code here.
	vector<vector<bool>> visited(n,vector<bool>(m,false));

    int dx[] = {0,1,0,-1,1,1,-1,-1};
    int dy[] = {1,0,-1,0,1,-1,1,-1};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){

                visited[i][j] = true;

                for(int k=0;k<8;k++){
                		if((i+dx[k]<n&&j+dy[k]<m&&i+dx[k]>=0&&j+dy[k]>=0)&&(board[i+dx[k]][j+dy[k]]==board[i][j]))
                		if(checkCycle(board,i,j,i+dx[k],j+dy[k],n,m,1,visited))
                		return true;
                }
            }
		}
	}

    return false;

}