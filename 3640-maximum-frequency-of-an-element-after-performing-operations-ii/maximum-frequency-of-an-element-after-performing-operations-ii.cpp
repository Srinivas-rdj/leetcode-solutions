class Solution {
public:
    int build(int i,int l,int r,vector<int>& cnt,vector<int>& seg){
        if(l==r) {seg[i]=cnt[l];
        return seg[i];
        }
        int mid=l+(r-l)/2;
        int x=build(2*i+1,l,mid,cnt,seg);
        int y=build(2*i+2,mid+1,r,cnt,seg);
        seg[i]=max(x,y);
        return seg[i];
    }
    int query(int i,int l1,int r1,int l,int r,vector<int>& seg){
        if(r1<l||l1>r) return 0;
        if(l1==r1||(l1==l&&r1==r)) return seg[i];
        int mid=l1+(r1-l1)/2;
        int x=query(2*i+1,l1,mid,l,r,seg);
        int y=query(2*i+2,mid+1,r1,l,r,seg);
        return max(x,y);
    }
    int maxFrequency(vector<int>& nums, int k, int op) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=0,ans=0;
        vector<int> v,cnt;
        for(int i=0;i<n;){
            int x=nums[i];
            int j=i;
            while(j<n&&nums[j]==x) j++;
            cnt.push_back(j-i);
            ans=max(ans,j-i);
            i=j;
            v.push_back(x);
        }
        set<pair<int,int>> s;
        for(int i=0;i<v.size();i++){
            s.insert({v[i]-k,-cnt[i]});
            s.insert({v[i]+k,cnt[i]});
        }
        vector<int> seg(4*v.size()+1,-1);
        build(0,0,v.size()-1,cnt,seg);
        int c=0,prev=-1e9;
        for(auto it:s){
            int x=it.first,y=-it.second;
            // cout<<x<<" "<<y<<"\n";
                int cnt2=min(op,c);
                if(c>op){
                    int l=lower_bound(v.begin(),v.end(),prev)-v.begin();
                    int r=upper_bound(v.begin(),v.end(),x)-v.begin();
                    int q;
                    // cout<<prev<<" "<<x<<" "<<"\n";
                    // cout<<l<<" "<<r<<"\n";
                    if(r==0||l==v.size()) q=0;
                    else q=query(0,0,v.size()-1,l,r-1,seg);
                    // cout<<q<<"\n";
                    cnt2=min(cnt2+q,c);
            }
                ans=max(ans,cnt2);
            prev=x;
            c+=y;
            maxi=max(c,maxi);
        }
        return ans;
    }
};