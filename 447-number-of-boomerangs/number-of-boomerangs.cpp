class Solution {
public:
    long long dist(vector<int>& a,vector<int>& b){
        return (a[0]-b[0])*1LL*(a[0]-b[0])+(a[1]-b[1])*1LL*(a[1]-b[1]);
    }
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int ans=0,n=p.size();
        for(int i=0;i<n;i++){
        map<long long,int> mp;
            for(int j=0;j<n;j++){
                if(j==i) continue;
                int d=dist(p[i],p[j]);
                ans+=2*mp[d];
                mp[d]++;
            }
        }
        return ans;
    }
};