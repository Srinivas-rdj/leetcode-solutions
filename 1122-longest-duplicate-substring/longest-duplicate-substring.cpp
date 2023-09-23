class Solution {
public:
    int p=31;
    long long m=INT_MAX;
    int findstr(vector<int>& h,int mid,string& s){
        unordered_map<int,int> mp;
        int pow_i=1;
        for(int i=h.size()-1;i-mid>=0;i--){
            int x=(h[i]*1LL-h[i-mid]+m)%m;
            x=(x*1LL*pow_i)%m;
            pow_i=(pow_i*1LL*p)%m;
            if(mp[x]>0){
                if(s.substr(i-mid,mid)==s.substr(mp[x]-mid,mid)) return i;
            }
            mp[x]=i;
        }
        return -1;
    }
    string longestDupSubstring(string s) {
        int l=1,r=s.size()-1;
        pair<int,int> ans={-1,-1};
        vector<int> h(s.size()+1);
        h[0]=0;
        int pow_i=1;
        for(int i=1;i<=s.size();i++){
            h[i]=(h[i-1]+((s[i-1]-'a'+1LL)*pow_i)%m)%m;
            pow_i=(pow_i*1LL*p)%m;
        }
        while(l<=r){
            int mid=l+(r-l)/2;
            int i=findstr(h,mid,s);
            if(i!=-1) {
                ans.first=i;
                ans.second=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        if(ans.first==-1 ) return "";
        return s.substr(ans.first-ans.second,ans.second);
    }
};