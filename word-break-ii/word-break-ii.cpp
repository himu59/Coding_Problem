class Solution {
public:
unordered_set<string> dict;
unordered_map<int,vector<string>> dp;

vector<string> helper(int start,string s) {
    if(dp.count(start)) return dp[start];
    vector<string> ans;
    
    if(start >= s.size()) {
        ans.push_back("");
    }
    
    for(int end = start+1; end <= s.size() ; end++) {
        string prefix = s.substr(start , end - start);
        if(dict.count(prefix)) {
            auto suffix = helper(end,s);
            
            for(string t : suffix) {
                ans.push_back(prefix + ((t == "") ? "" : " ") + t);
            }
        }
    }
    return dp[start] = ans;
}

vector<string> wordBreak(string A, vector<string> &B) {
        dict.clear();
        dp.clear();
        for(auto s : B) dict.insert(s);
        return helper(0,A);
    }   

};