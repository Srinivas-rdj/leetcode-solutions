class Solution {
public:
    bool isNStraightHand(vector<int>& h, int s) {
        sort(h.begin(),h.end());
        vector<int> v;
        for(int i=0;i<h.size();){
            int j=i;
            while(j<h.size()&&h[j]==h[i]) j++;
            if(i!=0&&h[i]!=h[i-1]+1) v.push_back(0);
            v.push_back(j-i);
            i=j;
        }
        vector<int> vec(v.size(),0);
        int x=0;
        for(int i=0;i<v.size();i++){ 
            x-=vec[i];
            v[i]-=x;
            if((v[i]!=0&&i+s>v.size())||v[i]<0) return 0;
          if(i+s<v.size())  vec[i+s]+=v[i];
            x+=v[i];
        }
        return 1;
    }
};