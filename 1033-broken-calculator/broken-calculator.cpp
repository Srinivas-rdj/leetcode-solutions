class Solution {
public:
    int brokenCalc(int s, int t) {
        int ans=0;
        while(s!=t){
            if(t>s&&t%2==0) t=t/2;
            else  t+=1;

            ans++;
        }
        return ans;
    }
};