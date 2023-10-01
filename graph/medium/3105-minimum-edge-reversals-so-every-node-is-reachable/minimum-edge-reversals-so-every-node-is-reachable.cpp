class Solution {
public:
    void dfs1(int i,vector<vector<pair<int,int>>>& tree,vector<int>& d,vector<int>& ans,int p){
        for(auto j:tree[i]){
            if(j.first!=p){
                ans[j.first]=ans[i];
                if(j.second==1) ans[j.first]--;
                else ans[j.first]++;
                dfs1(j.first,tree,d,ans,i);
            }
        }

    }
    int dfs(int i,vector<vector<pair<int,int>>>& tree,vector<int>& d,int p){
        int x=0;
        for(auto j:tree[i]){
           if(j.first!=p) {
               x+=j.second+dfs(j.first,tree,d,i);
           }
        }
        return d[i]=x;
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> tree(n);
        for(vector<int> v:edges){
            tree[v[0]].push_back({v[1],0});
            tree[v[1]].push_back({v[0],1});
        }
        vector<int> d(n,0);
        dfs(0,tree,d,-1);
        vector<int> ans(n,0);
        ans[0]=d[0];
        dfs1(0,tree,d,ans,-1);
        return ans;
    }
};