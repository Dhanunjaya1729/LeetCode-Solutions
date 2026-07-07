class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        int ans = 0;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            long long val = 1LL * mid * mid;

            if(val <= (long long) x){
                low = mid + 1;
                ans = mid;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};