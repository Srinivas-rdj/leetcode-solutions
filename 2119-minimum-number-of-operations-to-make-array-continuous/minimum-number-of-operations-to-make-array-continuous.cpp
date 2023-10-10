class Solution {
public:
    int minOperations(vector<int>& nums) {
    unordered_map<int,int> mp;
    vector<int> v;
    for(int i:nums){
        if(mp[i]==0){
            v.push_back(i);
        }
        mp[i]++;
    }
    sort(v.begin(),v.end());
    int n=nums.size();
    int ans=n;
    for(int i=0;i<v.size();i++){
        int x=(upper_bound(v.begin(),v.end(),v[i]+n-1)-v.begin())-i;
        ans=min(ans,n-x);
    }
    return ans;
    }
};