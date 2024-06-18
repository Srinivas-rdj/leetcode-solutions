class Solution {
public:
    void mergesort(int l,int r,vector<int>& nums,vector<int>& v,vector<int>& ans){
        if(l==r){
            return ;
        }
        int mid=(l+r)/2;
        mergesort(l,mid,nums,v,ans);
        mergesort(mid+1,r,nums,v,ans);
        int l1=l,r1=mid+1;
        vector<int> vec;
        while(l1<=mid&&r1<=r){
            if(nums[v[l1]]>nums[v[r1]]){
                vec.push_back(v[r1]);
                r1++;
            }
            else{
                vec.push_back(v[l1]);
                ans[v[l1]]+=r1-mid-1;
                l1++;
            }
        }
        while(r1<=r){
            vec.push_back(v[r1]);
            r1++;
        }
        while(l1<=mid){
            ans[v[l1]]+=r1-mid-1;
            vec.push_back(v[l1]);
            l1++;
        }
        for(int i=l;i<=r;i++) v[i]=vec[i-l];
        return ;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        vector<int> v(nums.size());
        for(int i=0;i<nums.size();i++) v[i]=i;
        mergesort(0,nums.size()-1,nums,v,ans);
        return ans;
    }
};