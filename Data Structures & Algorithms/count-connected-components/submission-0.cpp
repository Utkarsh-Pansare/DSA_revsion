class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int> & vis,int node){
        vis[node]=1;

        for(auto it:adj[node]){
           // cout<<it<<endl;
            if(!vis[it]){
                //cout<<it<<endl;
                dfs(adj,vis,it);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        
         for(int i=0 ; i<edges.size() ; i++){
            int u=edges[i][1];
            int v=edges[i][0];
           adj[u].push_back(v);
           adj[v].push_back(u); 
        }

        vector<int> vis(n,0);
        int cnt=0;

        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                //cout<<i<<endl;
                cnt++;
                dfs(adj,vis,i);
            }
        }
        return cnt;
    }
};
