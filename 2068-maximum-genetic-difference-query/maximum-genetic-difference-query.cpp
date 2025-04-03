class trie{
    public:
    vector<trie *> v;
    int cnt;
    trie(){
        v.resize(2,NULL);
        cnt=0;
    }
};

class Solution {
    trie* head;
public:
    void add(int x){
        trie* node=head;
        for(int i=19;i>=0;i--){
            int b=((x>>i)&1);
            if(node->v[b]==NULL){
                node->v[b]=new trie();
            }
            node=node->v[b];
            node->cnt++;
        }
    }
    void remove(int x){
        trie* node=head;
        for(int i=19;i>=0;i--){
            int b=((x>>i)&1);
            node=node->v[b];
            node->cnt--;
        }
    }
    int query(int x){
        trie* node=head;
        int ans=0;
        for(int i=19;i>=0;i--){
            int b=!((x>>i)&1);
            if(node->v[b]!=NULL&&node->v[b]->cnt!=0){
                ans+=(1<<i);
                node=node->v[b];
            }
            else{
                node=node->v[1-b];
            }
        }
        return ans;
    }
    void dfs(int i,int p,vector<vector<pair<int,int>>>& v,vector<vector<int>>& t,vector<int>& ans){
    add(i);
    for(pair<int,int> pr:v[i]){
        ans[pr.second]=query(pr.first);
    }
    for(int j:t[i]){
        if(j!=p) dfs(j,i,v,t,ans);
    }
    remove(i);
}
    vector<int> maxGeneticDifference(vector<int>& p, vector<vector<int>>& q) {
        head=new trie();
        int n=p.size();
        vector<vector<pair<int,int>>> v(n);
        int srt;
        vector<vector<int>> t(n);
        for(int i=0;i<q.size();i++){
            int x=q[i][0],val=q[i][1];
            v[x].push_back({val,i});
        }
        for(int i=0;i<n;i++){
          if(p[i]!=-1)  t[p[i]].push_back(i);
          else srt=i;
        }
        vector<int> ans(q.size());
        dfs(srt,-1,v,t,ans);
        return ans;
    }
};