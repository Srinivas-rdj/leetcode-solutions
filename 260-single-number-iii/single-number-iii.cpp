class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<32;i++){
            int x=0;
            for(int j:nums){
                if((j>>i)&(1LL)) x=x^j;
            }
            cout<<x<<"\n";
           int cnt=0;
           for(int j:nums){
            if(x==j) cnt++;
           }
           if(cnt==1) {
            ans.push_back(x);
            break;
             }
        }
        int x=0;
        for(int i=0;i<nums.size();i++){
            x=x^nums[i];
        }
        ans.push_back(x^ans[0]);
        return ans;
    }
};