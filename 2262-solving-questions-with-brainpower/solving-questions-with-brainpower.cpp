class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        vector<long long> v(n,0);
        v[n-1]=q[n-1][0];
        for(int i=n-2;i>=0;i--){
            long long x=0;
            if(i+q[i][1]+1<n) x=v[i+q[i][1]+1];
            v[i]=max(v[i+1],q[i][0]+x);
        }
        return v[0];
    }
};