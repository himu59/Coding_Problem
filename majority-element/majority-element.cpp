class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        
        int majidx = 0;
        int cnt = 1;
        for(int i=1;i<n;i++) {
            if(arr[i] == arr[majidx]) cnt++;
            else cnt--;
            if(cnt == 0) {
                majidx = i;
                cnt = 1;
            }
        }
        return arr[majidx];
    }
};