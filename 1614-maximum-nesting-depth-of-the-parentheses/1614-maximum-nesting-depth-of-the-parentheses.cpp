class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int x = 0;
        for(char ch: s){
            if(ch == '('){
                x++;
                maxi = max(maxi, x);
            }
            else if(ch == ')'){
                x--;
            }
        }
        return maxi;
    }
};