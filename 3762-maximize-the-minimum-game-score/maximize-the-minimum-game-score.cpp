class Solution {
public:
    bool ispos(vector<int>& v,long long mid,long long m){
        vector<long long> g(v.size(),0);
        m--;
        g[0]=v[0];
        for(int i=0;i<v.size()-1;i++){
            if(g[i]<mid){
                long long x=(mid-g[i])/v[i];
                if((mid-g[i])%v[i]) x++;
                if(m<2*x) return 0;
                m-=2*x;
                g[i+1] = v[i+1]*x;
            }
            if(m==0){
                if(g[v.size()-1]!=0) break;
                return 0;
            }
            g[i+1]+=v[i+1];
            m--;
            // cout<<m<<"\n";
        }
        int i=v.size()-1;
        if(g[i]<mid){
            long long x=(mid-g[i])/v[i];
                if((mid-g[i])%v[i]) x++;
                if(m<2*x) return 0;
                m-=2*x; 
        }
        return 1;
    }
    long long maxScore(vector<int>& v, int m) {
        long long l=0,r=1e15,ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(ispos(v,mid,m)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
            // cout<<mid<<" "<<ispos(v,mid,m)<<"\n";
        }
        return ans;
    }
};