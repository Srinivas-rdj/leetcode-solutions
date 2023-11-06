class Solution {
public:
    vector<long long> seg;
    long long maxsum(int ind,int l,int r,int l1,int r1){
        if(r1<l||l1>r) return LLONG_MIN;
        if(l>=l1&&r1>=r) return seg[ind];
        int mid=l+(r-l)/2;
        long long x1=maxsum(2*ind+1,l,mid,l1,r1),x2=maxsum(2*ind+2,mid+1,r,l1,r1);
        return max(x1,x2);
    }
    void update(int ind,int l,int r,int i,long long x){
            if(l==r){
                seg[ind]=x;
                return ;
            }
            int mid=l+(r-l)/2;
            if(i<=mid) update(2*ind+1,l,mid,i,x);
            else update(2*ind+2,mid+1,r,i,x);
            seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
            return ;
    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n=nums.size();
        seg.resize(4*n,0);
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i]-i,i});
        }
        long long ans=LLONG_MIN;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            long long x=maxsum(0,0,n-1,0,v[i][1]);
            ans=max(ans,x+nums[v[i][1]]);
            update(0,0,n-1,v[i][1],x+nums[v[i][1]]);
        }
        return ans;
    }
};