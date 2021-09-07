class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        
        map<string,int> deg;
        
        for(auto p : paths) {
            if(!deg.count(p[0])) deg[p[0]] = 0;
            if(!deg.count(p[1])) deg[p[1]] = 0;
            deg[p[0]]++;
        }
        
        for(auto it : deg) {
            if(it.second == 0) return it.first;
        }
        return "";
        
    }
};