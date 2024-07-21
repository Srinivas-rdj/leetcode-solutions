class Solution {
public:
    string losingPlayer(int x, int y) {
        int k=min(x,y/4);
        if(k%2==0) return "Bob";
        return "Alice";
    }
};