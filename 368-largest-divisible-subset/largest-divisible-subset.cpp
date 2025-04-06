class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=0,maxc=0;
        vector<int> par(n,-1),cnt(n,0);
       for(int i=0;i<nums.size();i++){
            int x=0,p=-1;
            for(int j=0;j<nums.size();j++){
                if(nums[i]%nums[j]==0){
                    if(cnt[j]>x){
                        x=cnt[j];
                        p=j;
                    }
                }
            }
            cnt[i]=x+1;
            par[i]=p;
            if(x+1>maxc){
                maxc=x+1;
                maxi=i;
            }
       }
       vector<int> ans;
       while(maxi!=-1){
        ans.push_back(nums[maxi]);
        maxi=par[maxi];
       }
       return ans;
    }
};