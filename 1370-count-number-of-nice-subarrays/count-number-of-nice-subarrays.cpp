class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int p=0,cnt=0,ans=0,od=0;
        int l=0,r=0;
        while(r<nums.size()){
            if(nums[r]%2) od++;
            if(od<k){
                if(nums[r]%2) cnt=1;
                else cnt++;
             }
             if(od==k){
                ans+=p*cnt;
                p=0;
                while(od==k){
                    p++;
                    if(nums[l]%2){
                        od--;
                    }
                    l++;
                }
                cnt=1;
             }
             r++;
        }
        ans+=p*cnt;
        return ans;
    }
};