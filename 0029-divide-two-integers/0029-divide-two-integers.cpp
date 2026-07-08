class Solution {
public:
    int divide(int dividend, int divisor) {
        long long val = (long long)dividend/divisor;
        if(val > INT_MAX){
            return INT_MAX;
        }
        else if(val < INT_MIN){
            return INT_MIN;
        }
        return (int)val;
    }
};