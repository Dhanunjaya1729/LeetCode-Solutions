class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int positive_idx = 0;
        int negative_idx = 1;

        for (int x : nums) {
            if (x > 0) {
                ans[positive_idx] = x;
                positive_idx += 2;
            } else {
                ans[negative_idx] = x;
                negative_idx += 2;
            }
        }

        return ans;
    }
};