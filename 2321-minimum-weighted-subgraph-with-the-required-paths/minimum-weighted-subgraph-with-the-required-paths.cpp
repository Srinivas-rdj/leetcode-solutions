class Solution {
public:
    void dijkstra(vector<vector<pair<int,int>>>& g,vector<long long>& dist,int s){
        dist[s]=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,s});
        while(!pq.empty()){
            int n=pq.top().second;
            long long d=pq.top().first;
            pq.pop();
            if(d>dist[n]) continue;
            for(pair<int,int> p:g[n]){
                if(dist[p.first]>p.second+d){
                    dist[p.first]=p.second+d;
                    pq.push({dist[p.first],p.first});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int s1, int s2, int d) {
        vector<vector<pair<int,int>>> g(n),g1(n);
        for(vector<int>& v:edges){
            g[v[0]].push_back({v[1],v[2]});
            g1[v[1]].push_back({v[0],v[2]});
        }
        long long ans=LLONG_MAX;
        vector<long long> d1(n,LLONG_MAX),d2(n,LLONG_MAX),d3(n,LLONG_MAX);
        dijkstra(g,d1,s1);
        dijkstra(g,d2,s2);
        dijkstra(g1,d3,d);
        for(int i=0;i<n;i++){
          if(d1[i]!=LLONG_MAX&&d2[i]!=LLONG_MAX&&d3[i]!=LLONG_MAX)  ans=min(ans,d1[i]+d2[i]+d3[i]);
        }
        if(ans==LLONG_MAX) return -1;
        return ans;
    }
};