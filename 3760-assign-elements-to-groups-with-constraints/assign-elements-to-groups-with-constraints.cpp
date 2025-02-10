class Solution {
public:
    void assign(int n,vector<int>& mark,vector<int>& ans,int ind){
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                // cout<<i<<" "<<mark[i]<<" "<<ans[ind]<<"\n";
                if(mark[i]!=-1&&(ans[ind]==-1||(mark[i]<ans[ind]))) ans[ind]=mark[i];
                if(mark[n/i]!=-1&&(ans[ind]==-1||(mark[n/i]<ans[ind]))) ans[ind]=mark[n/i];
            }
        }
    }
    vector<int> assignElements(vector<int>& v, vector<int>& e) {
        int n=v.size();
        vector<int> ans(n,-1);
        vector<int> mark(100001,-1);
        for(int i=0;i<e.size();i++){
            if(mark[e[i]]==-1) mark[e[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(ans[i]==-1){
                assign(v[i],mark,ans,i);
            }
        }
        return ans;
    }
};