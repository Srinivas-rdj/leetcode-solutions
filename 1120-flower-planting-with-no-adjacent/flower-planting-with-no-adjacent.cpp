class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n),dist(n+1,0);
        vector<vector<int>> v(n+1);
        for(vector<int>& vec:paths){
            v[vec[0]].push_back(vec[1]);
            v[vec[1]].push_back(vec[0]);
        }
        queue<int> q;
        vector<int> vis(n+1,0);
     for(int k=1;k<=n;k++)
     { if(vis[k]==0)  {
         q.push(k);
         vis[k]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=2;
            int i;
            for(i=0;i<4;i++){
                if(((dist[node]>>i)&1)==0) break;
            }
            ans[node-1]=i+1;
            for(int j:v[node]){
                if(vis[j]!=2){
                    dist[j]=dist[j]|(1<<i);
                 if(vis[j]==0)   q.push(j);
                }
            }
        }}}
        return ans;
    }
};