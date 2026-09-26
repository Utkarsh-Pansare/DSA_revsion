class Solution {
public:
    bool dfs(int node,int parent,vector<vector<int>> & adj,vector<int>& vis){
        vis[node]=1;

        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,node,adj,vis))return true;
            }
             else if(it!=parent){
                return true;
             }
        }
        return false;


    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0 ; i<edges.size() ; i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        
       bool found=!dfs(0,-1,adj,vis);
        for(int i=0 ; i<n ; i++){
           if(!vis[i])return false;
        }
        return found;
    }
};
