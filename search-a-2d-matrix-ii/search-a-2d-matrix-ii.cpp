class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int num) {
        int n = arr.size();
        int m = arr[0].size();
        
        int i = n-1,j = 0; // bottom left search
        
        while(i>=0 and j<m) {
            if(arr[i][j] == num) return true;
            else if(num > arr[i][j]) j++;
            else i--;
        }
        return false;
    }
};

// [1, 4, 7, 11,19] 19
// [2, 5, 8, 12,21]
// [3, 6, 9 ,16,22]
// [10,13,14,17,24]
// [18,19,23,26,30]