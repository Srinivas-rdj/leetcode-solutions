class Solution {
public:
int bin_search(long long x,int m){
    long long l=0,r=31,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(m*1LL*(1LL<<mid)+(1LL<<mid)-1<x-1) l=mid+1;
        else{
            ans=mid;
            r=mid-1;
        }
    }
    return ans;
}
    int minPatches(vector<int>& nums, int n) {
        sort(nums.begin(),nums.end());
        int maxi=0,ans=0;
        for(int i=0;i<nums.size()&&nums[i]<=n;i++){
            if(nums[i]>maxi+1){
                cout<<i;
                int x=bin_search(nums[i],maxi);
                ans+=x;
                maxi=nums[i]+maxi*(1<<x)+(1<<x)-1;
            }
            else maxi=maxi+nums[i];
        }
         if(n>maxi){
               int cnt=bin_search(n+1LL,maxi);
                ans+=cnt;
            }
            return ans;
    }
};