class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        stack<int> st;
        vector<int> v(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]<arr[i]) st.pop();
            if(st.empty()){
                v[i]=arr.size();
            }
            else{
                v[i]=st.top();
            }
            st.push(i);
        }
        int x=1,i=0;
        while(i<arr.size()){
            int y=v[i]-i;
            y-=x;
            if(y>=k||v[i]==arr.size()) return arr[i];
            x=0;
            i=v[i];
        }
        return arr[0];
    }
};