class Solution {
public:
    int smallestRangeI(vector<int>& arr, int k) {
        int max_ = -1;
        int min_ = INT_MAX;
        
        for(int i : arr) {
            max_ = max(max_,i);
            min_ = min(min_,i);
        }
        if(min_+k >= max_-k) return 0;
        else return abs((min_+k) - (max_-k));
                
    }
};

// 1 3 7 11 k=2
// 3 5 5 9                      