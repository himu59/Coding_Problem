class Solution {
public:
    bool isMatch(vector<int> &f1,vector<int> &f2) {
        for(int i=65;i<=122;i++) {
            // cout<<f1[i]<<' '<<f2[i]<<endl;
            if(f2[i] != 0 and f2[i] > f1[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string p) {
        vector<int> f1(200,0),f2(200,0);
        for(char c : p) f2[c+0]++;
        
        int n = s.size();
        int m = p.size();
        if(n < m or m == 0) return "";
        if(s == p) return s;
        
        int i=0,j=0;
        pair<int,int> idx = {-1,-1};
        string ans = "";
        int size = INT_MAX;
        while(j<n) {
            f1[s[j]+0]++;
            if(isMatch(f1,f2)) {
                // cout<<i<<' '<<j<<endl;
                if(size > j-i+1) {
                    size = j-i+1;
                    idx = {i,j};
                }
                while(i<=j and isMatch(f1,f2)) {
                    f1[s[i]+0]--;
                    i++;
                }
                if(size > j-i+2) {
                    idx = {i-1,j};
                    size = j-i+2;
                }
            }
            j++;
        }
        
        if(idx.first == -1) return "";
        for(int i=idx.first;i<=idx.second;i++) ans.push_back(s[i]);
        return ans;
    }
};