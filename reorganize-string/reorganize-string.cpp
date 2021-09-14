class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        int n = s.size();
        ans.resize(n);
        
        int freq[26] = {0};
        
        for(char c : s) freq[c-'a']++;
        
        int max_char = 0;
        int maxi = 0;
        
        for(int i=0;i<26;i++) {
            if(freq[i] > maxi) {
                maxi = freq[i];
                max_char = i;
            }
        }
        if(maxi > (n+1)/2) return "";
        
        int idx = 0;
        while(freq[max_char]) {
            char c = char(max_char+'a');
            ans[idx] = c;
            idx+=2;
            freq[max_char]--;
        }
        
        for(int i=0;i<26;i++) {
            
            while(freq[i]) {
                if(idx >= n) {
                    idx = 1;
                }
                char c = char(i+'a');
                ans[idx] = c;
                idx+=2;
                freq[i]--;
            }
        }
        return ans;
        
        
    }
};