class Solution {
public:
    void dfs(vector<vector<char>> & grid,vector<vector<int>> &vis,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n || i<0 || j>=m || j<0)return ;

        if(vis[i][j] || grid[i][j]!='1')return;
        vis[i][j]=1;
        dfs(grid,vis,i+1,j);
        dfs(grid,vis,i-1,j);
        dfs(grid,vis,i,j+1);
        dfs(grid,vis,i,j-1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0; i<n ;i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]=='1'&& vis[i][j]==0){
                    cnt++;
                    cout<<i<<j<<endl;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};
