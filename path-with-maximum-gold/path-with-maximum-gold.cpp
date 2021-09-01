class Solution {
public:
    int n,m;
    int vis[101][101];
    int dx[4] = { -1, 0, 0, 1 };
    int dy[4] = { 0, -1, 1, 0 };
    bool isValid(int i,int j) {
        if(i<0 or j<0 or i>=n or j>=m) return 0;
        return 1;
    }
    int dfs(int i,int j,vector<vector<int>>& grid) {
        if(grid[i][j] == 0) return 0;
        int mx_gold = 0;
        
        for(int x=0;x<4;x++) {
            int nx = dx[x]+i;
            int ny = dy[x]+j;
            if(isValid(nx,ny) and !vis[nx][ny]) {
                vis[nx][ny] = 1;
                mx_gold = max(mx_gold,dfs(nx,ny,grid));
                vis[nx][ny] = 0;
            }
        }
        return mx_gold+grid[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] != 0) {
                    memset(&vis,0,sizeof vis);
                    vis[i][j] = 1;
                    ans = max(ans,dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};