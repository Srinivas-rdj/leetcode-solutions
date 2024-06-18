class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<pair<int,int>> v;
        for(int i=0;i<d.size();i++){
            v.push_back({d[i],p[i]});
        }
        sort(v.begin(),v.end());
        sort(w.begin(),w.end());
        priority_queue<int> pq;
        int ans=0,l=0,r=0;
        while(r<w.size()){
            while(l<v.size()&&v[l].first<=w[r]) {pq.push(v[l].second);l++;}
            if(l!=0) ans+=pq.top();
            r++;
        }
        return ans;
    }
};