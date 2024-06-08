class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp; 
        mp[0]=0;
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                nums[i]+=nums[i-1];
            }
                nums[i]=nums[i]%k;
            if(nums[i]==0||mp[nums[i]]!=0){
                if(i+1-mp[nums[i]]>=2) return 1;
            }
            
            else mp[nums[i]]=i+1;
        }
        return 0;
    }
};