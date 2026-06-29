class Solution {
private:
    bool can_ship(const vector<int>& nums, const int capacity, const int days){
        int cnt_days = 1;
        int current_weight = 0;

        for(int i: nums){
            if(current_weight + i > capacity){
                cnt_days++;
                current_weight = 0;
            }
            current_weight += i;
        }

        return cnt_days <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(can_ship(weights, mid, days)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};