class Solution {
public:
    int maxFreeTime(int n, int k, vector<int>& st, vector<int>& et) {
        vector<int> v;
        int p=0;
        for(int i=0;i<st.size();i++){
            v.push_back(st[i]-p);
            p=et[i];
        }
        v.push_back(n-p);
        vector<int> prev(v.size()+1,0);
        for(int i=0;i<v.size();i++){
            prev[i+1]+=prev[i]+v[i];
        }
        int ans=0;
        for(int i=1;i<prev.size();i++){
            ans=max(ans,prev[i]-prev[max(i-k-1,0)]);
        }
        return ans;
    }
};