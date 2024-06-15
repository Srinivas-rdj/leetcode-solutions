class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        priority_queue<int> pq;
        int ans=w;
        vector<pair<int,int>> v;
        for(int i=0;i<p.size();i++){
            v.push_back({c[i],p[i]});
        }
        sort(v.begin(),v.end());
        int l=0;
        while(l<v.size()&&v[l].first<=w){
            pq.push(v[l].second);
            l++;
        }
        while(k-- && !pq.empty()){
            w+=pq.top();
            pq.pop();
             while(l<v.size()&&v[l].first<=w){
            pq.push(v[l].second);
            l++;
        }
        }
        return w;
    }
};