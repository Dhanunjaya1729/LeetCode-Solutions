class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i = 1; i*i <= num; i++){
            if(i*i == num){
                return true;
            }
            if(i == 46340){
                return false;
            }
        }
        return false;
    }
};