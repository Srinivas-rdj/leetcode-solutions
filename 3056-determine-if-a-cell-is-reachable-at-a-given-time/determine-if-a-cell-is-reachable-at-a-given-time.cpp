class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xdist=abs(sx-fx),ydist=abs(sy-fy);
        int x=min(xdist,ydist);
        int sum=xdist+ydist;
        x=sum-x;
        if(sum==0&&t==1) return 0;
        if(t>=x) return 1;
        return 0;
    }
};