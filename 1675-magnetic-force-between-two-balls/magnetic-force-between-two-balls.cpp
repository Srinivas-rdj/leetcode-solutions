class Solution {
public:
    int pos(vector<int>& nums,int n,int m){
        int cnt=1;
        int k=nums[0]+n;
        for(int p:nums){
            if(p>=k){
                cnt++;
                k=p+n;
            }
        }
        if(cnt>=m) return true;
        else return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l=1,r=1e9;
        int mid,ans;
        while(l<=r){
            mid=l+(r-l)/2;
            if(pos(position,mid,m)){
                ans=mid;
                l=mid+1;
                
            }
            else r=mid-1;
        }
        return ans;
    }
};