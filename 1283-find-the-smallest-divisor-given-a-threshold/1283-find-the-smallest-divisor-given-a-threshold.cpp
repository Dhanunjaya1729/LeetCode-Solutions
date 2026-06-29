class Solution {
private:
    bool helperFunc(const int mid, const vector<int>& nums, const int limit){
        long long sum = 0;
        for(auto i: nums){
            sum += (i + mid - 1)/mid;
        }
        return sum <= limit;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            bool isPossible = helperFunc(mid, nums, threshold);

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