class Solution {
public:
    int n,m;
    int dx[4] = { -1, 0, 0, 1 };
    int dy[4] = { 0, -1, 1, 0 };
    bool isValid(int i,int j) {
        if(i<0 or j<0 or i>=n or j>=m) return 0;
        return 1;
    }
    int dfs(int i,int j,vector<vector<int>>& grid) {
        if(grid[i][j] == 0) return 0;
        int mx_gold = 0;
        int num = grid[i][j];
        grid[i][j] = 0;
        for(int x=0;x<4;x++) {
            int nx = dx[x]+i;
            int ny = dy[x]+j;
            if(isValid(nx,ny)) {
                mx_gold = max(mx_gold,dfs(nx,ny,grid));
            }
        }
        grid[i][j] = num;
        return mx_gold+grid[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] != 0) {
                    ans = max(ans,dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};