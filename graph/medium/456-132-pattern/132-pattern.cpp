class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        vector<int> v(n,0);
        int mini=nums[0];
        v[0]=mini;
        for(int i=1;i<n;i++){
            if(nums[i]<=mini){ v[i]=nums[i];
            mini=nums[i];
            }
            else v[i]=v[i-1];
        } 
        set<int> s;
        s.insert(nums[n-1]);
        for(int i=n-2;i>=0;i--){
          
            if(nums[i]>v[i]) {
                auto it=s.upper_bound(v[i]);
              
                if(it!=s.end()&&(*it)<nums[i]) return 1;
            }
            s.insert(nums[i]);
        }
        return 0;
    }
};