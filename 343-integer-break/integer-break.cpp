class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int x=n/3,y=0;
        if(n%3==1){
            y=2;
            x--;
        }
        else if(n%3==2){
            y=1;
        }

        return pow(3,x)*pow(2,y);
    }
};