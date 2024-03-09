class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans=-1;
        unordered_map<int,int> mp;
        for(int i:nums1) mp[i]++;
        for(int i=0;i<nums2.size();i++){
            if(mp[nums2[i]]!=0){
                if(ans==-1) ans=nums2[i];
                else ans=min(ans,nums2[i]);
            }
        }
        return ans;
    }
};