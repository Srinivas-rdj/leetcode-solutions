class Solution {
public:
    int minChanges(int n, int k) {
        int cnt=0;
        for(int i=0;i<32;i++){
            if(((n>>i)&1)){
                if(((k>>i)&1)==0)  cnt++;
            }
            else{
                if((k>>i)&1) return -1;
            }
        }
        return cnt;
    }
};