class Solution {
public:
    bool winnerOfGame(string colors) {
        int c1=0,c2=0;
        for(int i=0;i<colors.size();){
            int j=i;
            while(j<colors.size()&&colors[i]==colors[j]){
                j++;
            }
            if(colors[i]=='A') c1+=max(0,j-i-2);
            else c2+=max(0,j-i-2);
            i=j;
        }
        return c1>c2;
    }
};