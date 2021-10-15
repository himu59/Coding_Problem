class Solution {
public:
    long long dp[505][505][2];
    int helper(int i,int j,vector<int> &nums,int turn) {
        if(i > j) return 0;
        if(dp[i][j][turn] != -1) return dp[i][j][turn];
        if(turn == 0)
            return dp[i][j][turn] = max(nums[i] + helper(i+1,j,nums,1),nums[j] + helper(i,j-1,nums,1));
        else
            return dp[i][j][turn] = min(helper(i+1,j,nums,0),helper(i,j-1,nums,0));
    }
    bool stoneGame(vector<int>& nums) {
        long long total = 0;
        memset(&dp,-1,sizeof dp);
        int n = nums.size();
        for(int i : nums) {
            total += (long long)i;
        }
        long long first = helper(0,n-1,nums,0);
        long long second = total-first;
        return (first >= second);
    }
};