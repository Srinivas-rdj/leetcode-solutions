class Solution {
public:
    int maxSatisfied(vector<int>& v, vector<int>& g, int k) {
        int ans=0,maxi=0,s=0;
        for(int i=0;i<v.size();i++){
            if(!g[i]) ans+=v[i];
            if(i<k){
                if(g[i]) maxi+=v[i];
                s=maxi;
            }
            else{
                if(g[i-k]) s-=v[i-k];
                if(g[i]) s+=v[i];
                maxi=max(maxi,s);
            }
        }
        return ans+maxi;
    }
};