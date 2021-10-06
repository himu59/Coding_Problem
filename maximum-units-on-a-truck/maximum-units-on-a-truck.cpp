class Solution {
public:
    static bool custom(vector<int> &a,vector<int> &b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& arr, int truckSize) {
        sort(arr.begin(),arr.end(),custom);
        
        int ans = 0;
        int cur = 0;
        for(auto i : arr) {
            if(cur > truckSize) break;
            int tmp = min(i[0],truckSize - cur);
            
            ans = ans + tmp*i[1];
            cur += tmp;
        }
        return ans;
    }
};
//  [[5,10],[2,5],[4,7],[3,9]]
// 50 + 27 + 14