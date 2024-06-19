class Solution {
public:
    bool ispos(vector<int>& v,int k,int m,int mid){
        int cnt=0;
        int l=0,r=0;
        while(r<v.size()){
            if(v[r]>mid||r-l+1==k){
                if(v[r]<=mid&&r-l+1==k) cnt++;
                r++;
                l=r;
                // maxi=0;
                // continue;
            }
            else{
                r++;
            }
        }
         return cnt>=m;  
    }
    int minDays(vector<int>& b, int m, int k) {
        int maxi=b[0],mini=b[0];
        for(int i=1;i<b.size();i++){
            maxi=max(b[i],maxi);
            mini=min(b[i],mini);
        }
        int l=mini,r=maxi,ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(ispos(b,k,m,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};