class Solution {
public:
    int dp[105][10005];
    int helper(int e,int f) {
        if(e == 1) return f;
        if(f == 0 or f == 1) return f;
        
        if(dp[e][f] != -1) return dp[e][f];
        
        int ans = INT_MAX,l=1,h=f;
        
        while(l<=h) {
            int mid = (l+h)/2;
            
            int left = helper(e-1,mid-1);
            int right = helper(e,f-mid);
            
            int tmp = 1 + max(left,right);
            
            if(left < right) l = mid+1;  //since we need more in worst case;
            else h = mid-1;
            
            ans = min(ans,tmp);
        }
        return dp[e][f] = ans;
        
    }
    int superEggDrop(int k, int n) {
        memset(&dp,-1,sizeof dp);
        return helper(k,n);
    }
};