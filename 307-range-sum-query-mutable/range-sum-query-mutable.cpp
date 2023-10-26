class NumArray {
public:
vector<int> bit,v;
    void bitupdate(int x,int val){
        int n=bit.size();
        while(x<n){
            bit[x]+=val;
            x+=(x&(-x));
        }
    }
    int bitsum(int x){
        int s=0;
        while(x>0){
            s+=bit[x];
            x-=(x&(-x));
        }
        return s;
    }
    NumArray(vector<int>& nums) {
        int n=nums.size()+1;
        bit.resize(n,0);
        v.resize(n-1,0);
        for(int i=1;i<n;i++){
            bitupdate(i,nums[i-1]);
            v[i-1]=nums[i-1];
        }
    }
    
    void update(int index, int val) {
        bitupdate(index+1,val-v[index]);
        v[index]=val;
    }
    
    int sumRange(int left, int right) {
        return bitsum(right+1)-bitsum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */