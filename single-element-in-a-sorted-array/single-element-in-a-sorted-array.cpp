class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int h = n-1;
        
        while(l<h) {
            int mid = (h+l)/2;
            if((mid%2 == 0 and arr[mid] == arr[mid+1]) or (mid%2 and arr[mid] == arr[mid-1])) {
                l = mid + 1;
            }else h = mid;
        }
        return arr[l];
    }
};