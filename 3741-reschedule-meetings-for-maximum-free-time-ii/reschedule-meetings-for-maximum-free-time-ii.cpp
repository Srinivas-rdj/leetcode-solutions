class Solution {
public:
    int maxFreeTime(int n, vector<int>& st, vector<int>& et) {
        int p=0;
        vector<pair<int,int>> gap;
        int ans=0;
        for(int i=0;i<st.size();i++){
            gap.push_back({st[i]-p,p});
            ans=max(ans,st[i]-p);
            p=et[i];
        }
        gap.push_back({n-p,p});
        sort(gap.begin(),gap.end());
        int n1=gap.size();
        p=0;
        for(int i=0;i<st.size();i++){
            int g1=st[i]-p,g2;
            if(i==st.size()-1) g2=n-et[i];
            else g2=st[i+1]-et[i];
            // cout<<i<<" "<<g1<<" "<<g2<<"\n";
            ans=max(ans,g1+g2);
            int s=et[i]-st[i];
            if(gap[n1-1].first>=s&&gap[n1-1].second!=et[i]&&gap[n1-1].second+gap[n1-1].first!=st[i]){
                // cout<<1<<"\n";
              ans=max(g1+g2+s,ans);  
            }
            if(n1>=2&&gap[n1-2].first>=s&&gap[n1-2].second!=et[i]&&gap[n1-2].second+gap[n1-2].first!=st[i]){
                // cout<<2<<"\n";
              ans=max(g1+g2+s,ans);  
            }
            if(n1>=3&&gap[n1-3].first>=s&&gap[n1-3].second!=et[i]&&gap[n1-3].second+gap[n1-3].first!=st[i]){
                // cout<<3<<"\n";
              ans=max(g1+g2+s,ans);  
            }
            p=et[i];
            // cout<<ans<<"\n";
        }
        
        return ans;
    }
};