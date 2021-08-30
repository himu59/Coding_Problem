class Solution {
public:
    static bool cmp(string &a,string &b)
    {
        if(a.size()==b.size())
        {
            return a<b;
        }
        return a.size()<b.size();
    }
    string kthLargestNumber(vector<string>& arr, int k) {
        sort(arr.begin(),arr.end(),cmp);
        for(auto i : arr) cout<<i<<' ';
        return arr[arr.size()-k];
    }
};