class Solution {
public:
    int n,m;
    int dx[4] = {0,-1,1,0};
    int dy[4] = {-1,0,0,1};
    int dp[205][205];
    bool isValid(int i,int j) {
        if(i<0 or j<0 or i>=n or j>=m) return false;
        else return true;
    }
    
    int dfs(int i,int j,vector<vector<int>>& arr) {
        if(dp[i][j] != -1)
            return dp[i][j];
        int max_path = 1;
        for(int x=0;x<4;x++) {
            int ni = dx[x]+i;
            int nj = dy[x]+j;
            
            if(isValid(ni,nj) and arr[i][j] < arr[ni][nj]) {
                max_path = max(max_path , dfs(ni,nj,arr)+1);
            }
        }
        return dp[i][j] = max_path;
    }
    
    int longestIncreasingPath(vector<vector<int>>& arr) {
        n = arr.size();
        m = arr[0].size();
        int res = 0;
        memset(&dp,-1,sizeof dp);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                res = max(res , dfs(i,j,arr));
            }
        }
        return res;
        
    }
};