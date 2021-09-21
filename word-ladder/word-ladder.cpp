class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordict) {
        
        unordered_set<string> map(wordict.begin(), wordict.end());
        queue<string> Q;
        Q.push(start);
        int ladder = 1;
        
        while(!Q.empty()) {
            int sz = Q.size();
            while(sz--) {
                string word = Q.front();
                Q.pop();
                
                if(word == end) return ladder;
                map.erase(word);
                
                for(int i=0;i<word.size();i++) {
                    char c = word[i];
                    for(int j=0;j<26;j++) {
                        word[i] = 'a' + j;
                        
                        if(map.find(word) != map.end()) {
                            Q.push(word);
                        }
                    }
                    word[i] = c;
                }
            }
            ladder++;
        }
        return 0;
    }
};