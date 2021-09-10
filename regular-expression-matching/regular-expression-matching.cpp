class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        int dp[n+1][m+1];
        memset(&dp,0,sizeof dp);
        
        dp[0][0] = 1;
    
        for(int i=1;i<=m;i++) {
            if(p[i-1] == '*' and dp[0][i-2]) dp[0][i] = 1;
        } 
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(p[j-1] == s[i-1] or p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1] == '*') {
                    if(j-2>=0 and dp[i][j-2] == 1) dp[i][j] = 1;
                    else if(j-2>=0 and (p[j-2] == s[i-1]) or p[j-2] == '.') {
                        dp[i][j] = dp[i][j-1] or dp[i-1][j];
                    }
                }
            }
        }
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) cout<<dp[i][j]<<' ';
            cout<<endl;
            
        }
            
        return dp[n][m];
    }
};