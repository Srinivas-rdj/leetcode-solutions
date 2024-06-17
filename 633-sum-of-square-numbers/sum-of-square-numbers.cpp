class Solution {
public:
    bool judgeSquareSum(int c) {
        int x=sqrt(c);
        for(int i=0;i<=x;i++){
            int y=c-i*i;
            int z=sqrt(y);
            if(z*z==y) return 1;
        }
        return 0;
    }
};