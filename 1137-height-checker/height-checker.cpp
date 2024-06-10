class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> v=h;
        sort(h.begin(),h.end());
        int ans=0;
        for(int i=0;i<h.size();i++){
            if(v[i]!=h[i]) ans++;
        }
        return ans;
    }
};