class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& arr, int k) {
        int n = arr.size(), m = arr[0].size();
        int mid;
        int l = 0,r = m*n-1;
        while(l<=r) {
            mid = l + (r-l)/2;
            if(arr[mid / m][mid % m] == k) return true;
            if(arr[mid / m][mid % m] < k) {
                l = mid+1;
            }else {
                r = mid-1;
            }
        }
        return false;
    }
};