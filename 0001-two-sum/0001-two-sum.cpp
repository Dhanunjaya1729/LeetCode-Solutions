class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int needed_num = target - num;
            if (mpp.find(needed_num) != mpp.end()) {
                return {mpp[needed_num], i};
            }
            mpp[num] = i;
        }
        return {};
    }
};