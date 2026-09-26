class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
       vector<vector<int>> adj(n);
        vector<int> inorder(n,0);
        vector<int> ans;

        for(int i=0 ; i<pre.size() ; i++){
            int u=pre[i][1];
            int v=pre[i][0];
           adj[u].push_back(v);
           inorder[v]++;
        }
        queue<int> q;

        for(int i=0 ; i<n ; i++){
            if(inorder[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            cnt++;

            for(auto it:adj[node]){
                inorder[it]--;
                if(inorder[it]==0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        vector<int> v={};
       return ans.size()==n? ans:v; 
    }
};
