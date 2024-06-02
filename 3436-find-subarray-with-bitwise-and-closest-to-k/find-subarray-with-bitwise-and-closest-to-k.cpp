class Solution {
public:
    void add(vector<int>& a,int x){
        for(int i=0;i<32;i++){
            if(!((x>>i)&1)) a[i]++;
        }
    }
    int remove(vector<int>& a,int x,int y){
        for(int i=0;i<32;i++){
            if(!((x>>i)&1)) {a[i]--;
            if(a[i]==0) y+=(1<<i);
            }
        }
        return y;
    }
    
    int minimumDifference(vector<int>& nums, int k) {
        vector<int> a(32,0);
        int ans=1e9+5,l=0,r=0,x=nums[0];
        while(r<nums.size()){
            add(a,nums[r]);
           x=x&nums[r];
            // cout<<l<<" "<<r<<" "<<x<<"\n";
            ans=min(abs(k-x),ans);
            while(l<=r&&x<=k){
                x=remove(a,nums[l],x);
                ans=min(abs(k-x),ans);
                l++;
            }
            r++;
        }
        return ans;
    }
};