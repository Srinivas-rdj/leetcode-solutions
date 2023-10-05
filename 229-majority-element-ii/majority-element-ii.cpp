class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        float cnt1=0,el=INT_MIN,cnt2=0,el2=INT_MIN;
        for(int i:nums){
            if(cnt1==0&&el2!=i){
                el=i;
            }
            else if(cnt2==0&&el!=i){
                el2=i;
            }
            
            if(i==el) cnt1++;
           else if(i==el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
            
        }
     
        cnt1=0,cnt2=0;
        for(int i:nums){
            if(i==el) cnt1++;
            if(i==el2) cnt2++;
        }
     
        vector<int> v;
        if(cnt1>nums.size()/3.0) v.push_back(el);
        if(cnt2>nums.size()/3.0) v.push_back(el2);
        return v;
    }
};