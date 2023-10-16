class Solution {
public:
    vector<int> getRow(int ind) {
     if(ind==0) return {1};
     vector<int> ans;
     ans.push_back(1);
     int x=1,s=ind;
     for(int i=1;i<=ind;i++){
         x=(x*1LL*s)/i;
         s--;
         ans.push_back(x);
     }   
     return ans;
    }
};