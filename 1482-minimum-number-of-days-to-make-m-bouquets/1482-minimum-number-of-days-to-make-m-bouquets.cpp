class Solution {
private:
    bool possible(const int n, const vector<int>& nums, const int days, const int m, const int k){
        int cnt = 0;
        int noOfB = 0;

        for(int i: nums){
            if(i <= days){
                cnt++;
            }
            else{
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = k * 1LL * m * 1LL;
        if(val > 1LL * n){
            return -1;
        }

        int low = INT_MAX;
        int high = INT_MIN;
        for(int i: bloomDay){
            low = min(low, i);
            high = max(high, i);
        }

        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            bool isPossible = possible(n, bloomDay, mid, m, k);

            if(isPossible){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};