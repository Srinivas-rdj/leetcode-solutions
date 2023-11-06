class Solution {
public:
    vector<long long> bit;
    void update(int x,int n){
        while(x<n){
            bit[x]++;
            x+=x&(-x);
        }
    }
    long long sum(int x){
        long long s=0;
        while(x>0){
            s+=bit[x];
            x-=x&(-x);
        }
        return s;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        vector<vector<int>> d,v;
        for(int i=0;i<n;i++){ d.push_back({nums1[i]-nums2[i],i+1});
        v.push_back({nums1[i]-nums2[i]+diff,i+1});
        }
        sort(v.begin(),v.end());
        sort(d.begin(),d.end());
        bit.resize(n+1,0);
        int j=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            while(j<n&&d[j][0]<=v[i][0]){
                update(d[j][1],n+1);
                j++;
            }
            ans+=sum(v[i][1]-1);
        }
        return ans;
    }
};