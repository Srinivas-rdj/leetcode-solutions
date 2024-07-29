class Solution {
public:
    int nonSpecialCount(int l, int r) {
        vector<int> v(1e5+1,1);
        v[0]=0;
        v[1]=0;
        for(int i=2;i*i<=1e5;i++){
            if(v[i]){
                for(int j=i*i;j<1e5;j+=i) v[j]=0;
            }
        }
        vector<long long> primes;
        for(int i=2;i<=1e5;i++){
            if(v[i]) primes.push_back((long long)i*i);
        }
        int x=lower_bound(primes.begin(),primes.end(),l)-primes.begin();
        int y=upper_bound(primes.begin(),primes.end(),r)-primes.begin();
        return (r-l+1)-(y-x);
    }
};