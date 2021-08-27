class Solution {
public:
    #define pii pair<int,int> 
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        
        for(int i=0;i<n;i++) {
            int last_pos_one = 0;
            int l=0,r=m-1;
            while(l<=r) {
                int mid = (l+r)/2;
                if(mat[i][mid] == 1) {
                    last_pos_one = mid+1;
                    l = mid+1;
                }else r = mid-1;
            }
            pq.push({last_pos_one,i});
        }
        int i=0;
        vector<int> ans;
        while(!pq.empty() and i<k) {
            ans.push_back(pq.top().second);
            pq.pop(); i++;
        }
        return ans;
    }
};