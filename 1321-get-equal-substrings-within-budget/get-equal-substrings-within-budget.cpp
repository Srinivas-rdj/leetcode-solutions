class Solution {
public:
    bool ispos(vector<int>& v,int m,int mc){
        if(v[m-1]<=mc) return 1;
        for(int i=m;i<v.size();i++){
            if(v[i]-v[i-m]<=mc) return 1;
        }
        return 0;
    }
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> scr(s.size());
        for(int i=0;i<s.size();i++){
            scr[i]=abs(s[i]-t[i]);
            if(i!=0) scr[i]+=scr[i-1];
        }
        int l=1,r=s.size(),ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(ispos(scr,mid,maxCost)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};