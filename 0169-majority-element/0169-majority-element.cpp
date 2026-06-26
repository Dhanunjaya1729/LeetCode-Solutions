class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele;
        int cnt = 0;

        for (int i : nums) {
            if (cnt == 0) {
                ele = i;
                cnt++;
            } else if (ele == i) {
                cnt++;
            } else {
                cnt--;
            }
        }

        cnt = 0;
        for (int i : nums) {
            if (i == ele) {
                cnt++;
            }
        }

        if (cnt > n / 2) {
            return ele;
        }

        return -1;
    }
};