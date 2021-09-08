class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b) {
        return a[1] < b[1]; 
    }
    int scheduleCourse(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),comp);
        int time = 0;
        priority_queue<int> pq;
        for(auto c : arr) {
            if(c[0] <= c[1]) {
                if(c[0]+time <= c[1]) {
                    time += c[0];
                    pq.push(c[0]);
                }else {
                    if(!pq.empty() and pq.top() > c[0]) {
                        time -= pq.top();
                        pq.pop();
                        time += c[0];
                        pq.push(c[0]);
                    }
                }
            }
        }
        return pq.size();
    }
};