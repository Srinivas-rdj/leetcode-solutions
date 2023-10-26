class LUPrefix {
public:
        vector<int> bit;
    void update(int x){
        int n=bit.size();
        while(x<n){
            bit[x]++;
            x+=(x&(-x));
        }
    }
    int sum(int x){
        int s=0;
        while(x>0){
            s+=bit[x];
            x-=(x&(-x));
        }
        return s;
    }
    LUPrefix(int n) {
        bit.resize(n+1,0);
    }
    
    void upload(int v) {
        update(v);
    }
    
    int longest() {
        int l=1,r=bit.size()-1,ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(sum(mid)==mid){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */