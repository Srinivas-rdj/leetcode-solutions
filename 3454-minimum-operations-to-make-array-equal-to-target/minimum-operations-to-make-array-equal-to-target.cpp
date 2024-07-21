class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
     long long ans=0;
     int b=0,cnt=0;
     for(int i=0;i<nums.size();i++){
        if(nums[i]<target[i]&&b==0){
            int x=target[i]-nums[i];
            if(x>cnt) ans+=x-cnt;
            cnt=x;
        }
        else if(nums[i]>target[i]&&b){
            int x=nums[i]-target[i];
            if(x>cnt) ans+=x-cnt;
            cnt=x;
        }
        else if(nums[i]==target[i]) cnt=0;
        else{
            ans+=abs(nums[i]-target[i]);
            cnt=abs(nums[i]-target[i]);
            if(nums[i]>target[i]) b=1;
            else b=0;
        }
     }  
     return ans; 
    }
};