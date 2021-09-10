class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        stack<long> st,pt;
        int n = arr.size();
        
        vector<long> next_smaller(n),prev_smaller(n);
        
        for(int i=0;i<n;i++) {
            next_smaller[i] = n-i-1;
            prev_smaller[i] = i;
        }
        
        for(int i=0;i<n;i++) {
            while(!st.empty() and arr[i] < arr[st.top()]) {
                next_smaller[st.top()] = i-st.top()-1;
                st.pop();
            }
            st.push(i);
        }
        for(int i=n-1;i>=0;i--) {
            while(!pt.empty() and arr[i] <= arr[pt.top()]) {
                prev_smaller[pt.top()] = pt.top()-1-i;
                pt.pop();
            }
            pt.push(i);
        }
        long ans = 0;
        for(int i=0;i<n;i++) {
            ans += ((prev_smaller[i] + 1) * (next_smaller[i] + 1) * arr[i]);
            ans %= mod;
        }
        return ans;
    }
};