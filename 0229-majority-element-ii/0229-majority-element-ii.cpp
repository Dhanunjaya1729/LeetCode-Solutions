class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;

        for (int i : nums) {
            if (cnt1 == 0 && ele2 != i) {
                ele1 = i;
                cnt1++;
            } else if (cnt2 == 0 && ele1 != i) {
                ele2 = i;
                cnt2++;
            } else if (ele1 == i) {
                cnt1++;
            } else if (ele2 == i) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for (int i : nums) {
            if (ele1 == i) {
                cnt1++;
            } else if (ele2 == i) {
                cnt2++;
            }
        }

        vector<int> v;
        int min_count = nums.size() / 3 + 1;

        if (cnt1 >= min_count) {
            v.push_back(ele1);
        }

        if (cnt2 >= min_count) {
            v.push_back(ele2);
        }

        return v;
    }
};