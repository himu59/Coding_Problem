class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int max_so_far = v[0];
        int cur_max = v[0];
        int len = v.size();
        for(int i=1;i<len;i++)
        {
            cur_max = max(v[i],v[i]+cur_max);
            max_so_far = max(cur_max,max_so_far);
        }
        return max_so_far;
    }
};