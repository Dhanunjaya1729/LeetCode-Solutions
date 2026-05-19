class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                if (nums[i] == n) {
                    n++;
                } else if (nums[i] > n) {
                    break;
                }
            }
        }
        return n;
    }
};