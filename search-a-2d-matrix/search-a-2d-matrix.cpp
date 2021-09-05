class Solution {
public:
    bool binary_search(int l,int r,vector<int> &arr,int k) {
        while(l<=r) {
            int mid = (l+r)/2;
            if(arr[mid] == k) return true;
            if(arr[mid] > k) r = mid-1;
            else l = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& arr, int k) {
        int n = arr.size(), m = arr[0].size();
        
        int l = 0,r = n-1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(arr[mid][0] <= k and k <= arr[mid][m-1]) {
                return binary_search(0,m-1,arr[mid],k);
            }else if(arr[mid][0] > k) r = mid-1;
            else l = mid+1;
        }
        return false;
    }
};