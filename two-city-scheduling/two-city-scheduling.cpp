class Solution { 
public:
    #define pii pair<int,int>
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<pii> pq;
        int n = costs.size();
        for(int i=0;i<n;i++) {
            pq.push({costs[i][1] - costs[i][0], i});
        }
        
        int i = 0;
        int ans = 0;
        while(!pq.empty()) {
            i++;
            int x;
            if(i <= n/2) {
                x = pq.top().second;
                ans += costs[x][0];
            }else {
                x = pq.top().second;
                ans += costs[x][1]; 
            }
            cout<<x<<' ';
            pq.pop();
        }
        return ans;
    }
};