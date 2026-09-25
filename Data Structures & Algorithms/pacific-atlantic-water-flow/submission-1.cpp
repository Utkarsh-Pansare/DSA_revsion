class Solution {
public:
int n,m;

   void dfs(vector<vector<int>> & heights , vector<vector<int>> & vis,int i,int j){
      if(i>=n ||i<0 || j>=m||j<0 ) return;
        
       if(vis[i][j])return;

        int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        vis[i][j]=1;

        for(auto &d:dir){
            int ni=i+d[0];
            int nj=j+d[1];

            if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;
            
            if(heights[ni][nj]<heights[i][j])continue;
            dfs(heights,vis,ni,nj);
        }
   }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();

        vector<vector<int>> p(n,vector<int>(m,0));
         vector<vector<int>> a(n,vector<int>(m,0));

         for(int i=0 ; i<n ; i++){
            dfs(heights,p,i,0);
         }
         for(int i=0 ; i<m ; i++){
            dfs(heights,p,0,i);
         }
         for(int i=0 ; i<m ; i++){
            dfs(heights,a,n-1,i);
         }
         for(int i=0 ; i<n ; i++){
            dfs(heights,a,i,m-1);
         }
        vector<vector<int>> ans;
         for(int i=0 ; i<n; i++){
            for(int j=0;  j<m ; j++){
                if(a[i][j]&p[i][j]){
                    ans.push_back({i,j});
                }
            }
         }
         return ans;

    }
};
