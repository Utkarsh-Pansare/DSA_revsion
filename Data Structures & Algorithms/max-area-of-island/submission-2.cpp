class Solution {
public:
int ans=0;
  int dfs(vector<vector<int>>& grid ,vector<vector<int>> & vis,int i,int j,int cnt){
    if(i>=grid.size()|| i<0 || j>=grid[0].size() || j<0 )return 0;
    
    if(vis[i][j] || grid[i][j]!=1)return 0;
    vis[i][j]=1;
   int area=1;
   area+= dfs(grid,vis,i+1,j,cnt+1);
   area+=  dfs(grid,vis,i-1,j,cnt+1);
   area+=  dfs(grid,vis,i,j+1,cnt+1);
   area+=  dfs(grid,vis,i,j-1,cnt+1);

   return area;

  }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size()  ; j++){
                if(!vis[i][j] && grid[i][j]==1){
                   int area= dfs(grid,vis,i,j,1);
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
};
