class Solution {
public:
    char kthbit(int n,int x,int k){
        if(n==1){
            if(x==0) return '1';
            return '0';
        }
        int t=(1LL<<(n-1));
        if(t==k){
            return x+'0';
        }
        if(k<t){
            return kthbit(n-1,1,k);
        }
        k-=t;
        return kthbit(n-1,0,k);
    }
    char findKthBit(int n, int k) {
        return kthbit(n,1,k);
    }
};