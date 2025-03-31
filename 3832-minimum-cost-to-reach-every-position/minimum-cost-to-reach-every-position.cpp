class Solution {
public:
    vector<int> minCosts(vector<int>& v) {
        int n=v.size(),mini=INT_MAX;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            mini=min(v[i],mini);
            ans[i]=mini;
        }
        return ans;
    }
};