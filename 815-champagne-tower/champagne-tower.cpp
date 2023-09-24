class Solution {
public:
    double champagneTower(int s, int r, int c) {
        if(r==0&&c==0){
            if(s>=1) return 1;
            else return 0;
        }
       vector<double> prev(1,s);
        int r1=1;
        while(r1<=r){
            vector<double> v(r1+1,0);
         if(prev[0]>=1)   v[0]=(prev[0]-1)/2.0;
            for(int i=1;i<r1;i++){
                if(prev[i]>=1) v[i]+=(prev[i]-1)/2.0;
                if(prev[i-1]>=1) v[i]+=(prev[i-1]-1)/2.0;
            }
        if(prev[r1-1]>=1)  v[r1]=(prev[r1-1]-1)/2.0;
            prev=v;
            r1++;
        }
        if(prev[c]>=1) return 1.0;
        return prev[c];
    }
};