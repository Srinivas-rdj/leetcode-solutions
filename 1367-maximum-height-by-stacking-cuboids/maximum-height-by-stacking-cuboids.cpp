class Solution {
public:
    int maxHeight(vector<vector<int>>& c) {
       priority_queue<pair<int,int>> pq;
       map<vector<int>,int> mp;
       for(vector<int> a:c){
        sort(a.begin(),a.end());
        mp[a]++;
       }
      vector<vector<int>> v;
      int i=0;
      for(auto t:mp){
        vector<int> vec=t.first;
        int cnt=t.second;
        cout<<cnt<<"\n";
        int a=vec[0],b=vec[1],d=vec[2];
        v.push_back({a,b,d,i,cnt});
        v.push_back({b,a,d,i,cnt});
        v.push_back({a,d,b,i,cnt});
        v.push_back({d,a,b,i,cnt});
        v.push_back({d,b,a,i,cnt});
        v.push_back({b,d,a,i,cnt});
        i++;
      }
       vector<int> dist(v.size());
    for(int i=0;i<v.size();i++){
        dist[i]=v[i][2]*v[i][4];
        pq.push({dist[i],i});
    }
    int ans=0;
        while(!pq.empty()){
            int ind=pq.top().second;
            vector<int> vec=v[ind];
            int h=pq.top().first;
            ans=max(ans,h);
            pq.pop();
            if(dist[ind]>h) continue;
            for(int i=0;i<v.size();i++){
                if(v[i][3]!=v[ind][3]){
                    if(dist[i]<h+v[i][2]*v[i][4]&&v[i][0]<=vec[0]&&v[i][1]<=vec[1]&&v[i][2]<=vec[2]) {
                        dist[i]=h+v[i][2]*v[i][4];
                        pq.push({dist[i],i});
                    }
                }
            }
        }
      return ans;  
    }
};