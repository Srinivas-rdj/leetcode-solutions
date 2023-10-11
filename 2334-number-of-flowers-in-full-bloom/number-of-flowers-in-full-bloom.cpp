class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        int n=p.size();
        vector<int> ans(n,0);
        vector<vector<int>> v;
        for(int i=0;i<n;i++) v.push_back({p[i],i});
        sort(v.begin(),v.end());
        vector<vector<int>> vec;
        for(int i=0;i<f.size();i++){
            vec.push_back({f[i][0],1});
            vec.push_back({f[i][1]+1,-1});
        }
        sort(vec.begin(),vec.end());
        int l=0,x=0;
        for(int i=0;i<vec.size();i++){
            while(l<n&&v[l][0]<vec[i][0]){
                ans[v[l][1]]=x;
                l++;
            }
            x+=vec[i][1];
        }
        while(l<n){
            ans[v[l][1]]=x;
            l++;
        }
        return ans;
    }
};