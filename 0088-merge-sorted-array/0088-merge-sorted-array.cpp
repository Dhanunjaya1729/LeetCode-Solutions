class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        temp.reserve(m + n);
        int low = 0;
        int mid = m - 1;
        int high = m + n - 1;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high) {
            if (nums1[left] <= nums2[right - m]) {
                temp.push_back(nums1[left]);
                left++;
            } else {
                temp.push_back(nums2[right - m]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(nums1[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(nums2[right - m]);
            right++;
        }
        for (int i = 0; i <= high; i++) {
            nums1[i] = temp[i];
        }
    }
};