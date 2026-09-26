class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<int,int>> q;

        for(int i=0 ; i<n ; i++){
            if(board[i][0]=='O')q.push({i,0});
        }
         for(int i=0 ; i<n ; i++){
            if(board[i][m-1]=='O')q.push({i,m-1});
        }
         for(int i=0 ; i<m ; i++){
            if(board[0][i]=='O')q.push({0,i});
        }
         for(int i=0 ; i<m ; i++){
            if(board[n-1][i]=='O')q.push({n-1,i});
        }

        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();

                vis[i][j]=1;
            for(auto &d:dir){
                int ni=i+d[0];
                int nj=j+d[1];

                if(ni>=n || ni<0|| nj<0 || nj>=m)continue;
                if(board[ni][nj]=='X')continue;
                if(vis[ni][nj])continue;
                q.push({ni,nj});
            }
        }

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m; j++){
                
                if(vis[i][j]==0 && board[i][j]=='O')board[i][j]='X';
            }
        }
    }
};
