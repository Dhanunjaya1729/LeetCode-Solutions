class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefixSumMap;
        int prefixSum = 0;
        int count = 0;
        prefixSumMap[0] = 1;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int sumToRemove = prefixSum - k;
            count += prefixSumMap[sumToRemove];
            prefixSumMap[prefixSum] += 1;
        }

        return count;
    }
};