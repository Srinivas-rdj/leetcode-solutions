class Solution {
public:
    int maxDistance(string s, int k) {
        int ans=0;
        int d1=0,d2=0,d3=0,d4=0;
        for(char c:s){
            if(c=='N'){
                d1++;
            }
            else if(c=='S') d2++;
            else if(c=='E') d3++;
            else d4++;
            if(d2+d4>k){
                ans=max(ans,d1+d3+2*k-d2-d4);
            }
            else ans=max(ans,d1+d3+min(k,d2+d4));
            if(d2+d3>k){
                ans=max(ans,d1+d4+2*k-d2-d3);
            }
            else ans=max(ans,d1+d4+min(k,d2+d3));
            if(d1+d4>k){
                ans=max(ans,d2+d3+2*k-d1-d4);
            }
            else ans=max(ans,d2+d3+min(k,d1+d4));
            if(d1+d3>k){
                ans=max(ans,d2+d4+2*k-d1-d3);
            }
            else ans=max(ans,d2+d4+min(k,d1+d3));
        }
        return ans;
    }
};