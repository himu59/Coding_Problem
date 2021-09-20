class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int mn = arr[0];
        int mx = arr[0];
        int ans = arr[0];
        
        for(int i=1;i<n;i++) {
            int tmp = mx;
            mx = max({arr[i] , tmp*arr[i] , mn*arr[i]});
            mn = min({arr[i] , tmp*arr[i] , mn*arr[i]});
            ans = max(ans,mx);
        }
        return ans;
    }
};

// min a[i] 
// max a[i];