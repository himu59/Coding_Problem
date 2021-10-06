class Solution {
public:
    int canCompleteCircuit(vector<int>& petrol, vector<int>& cost) {
        int start = 0;
        int cal = 0;
        int deficit = 0;
        
        for(int i=0;i<petrol.size();i++) {
            cal += petrol[i] - cost[i];
            
            if(cal < 0) {
                start = i+1;
                deficit += cal;
                cal = 0;
            }
        }
        return (cal + deficit) >= 0 ? start : -1;
    }
};