class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
       long long ans=0;
       vector<pair<int,int>> v;
       for(int i=0;i<nums1.size();i++){
        v.push_back({nums2[i],nums1[i]});
       }
       sort(v.begin(),v.end());
       priority_queue<int,vector<int>,greater<int>> pq;
       long long sum=0;
       int n=v.size();
       for(int i=n-1;i>=n-k;i--){
        pq.push(v[i].second);
        sum+=v[i].second;
       }
       ans=max(ans,sum*v[n-k].first);
    //    cout<<n-k-1<<" "<<pq.top()<<"\n";
       for(int i=n-k-1;i>=0;i--){
        int x=pq.top();
        pq.pop();
        ans=max(v[i].first*(sum-x+v[i].second),ans);
        sum=sum-x+v[i].second;
        pq.push(v[i].second);
       }
       return ans;
    }
};