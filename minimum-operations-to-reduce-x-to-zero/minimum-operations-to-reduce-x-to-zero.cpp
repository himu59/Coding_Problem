class Solution {
public:
    int minOperations(vector<int>& arr, int x) {
        int n = arr.size();
        map<int,int> mp;
        int sum = 0;
        int ans = INT_MAX;
        for(int i=0;i<n;i++) {
            sum += arr[i];
            mp[sum] = i;
            if(sum == x) ans = i+1;
        }
        sum = 0;
        for(int i=n-1;i>=0;i--) {
            sum += arr[i];
            if(sum == x) ans = min(ans,n-i);
            if(mp.count(x - sum) and mp[x-sum] < i) {
                ans = min(ans , n-i + mp[x-sum]+1);
            }
        }
        return ans == (INT_MAX) ? -1 : ans;
    }
};
// [1,1] , 3
// [1-0] [2,0]
// [0,1,2,3,4]
// [1,1,4,2,3] , 5
// [1,2,6,8,11]

// [3,2,20, 1, 1, 3] 10
// [3,5,25,26,27,28]