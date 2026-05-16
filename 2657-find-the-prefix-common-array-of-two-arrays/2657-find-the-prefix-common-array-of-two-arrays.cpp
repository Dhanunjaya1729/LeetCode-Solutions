class Solution {
private:
    vector<int> common_array(vector<int> n1, vector<int> n2, const int n) {
        vector<int> common_elements;
        vector<int> nums1;
        vector<int> nums2;
        for (int a = 0; a <= n; a++) {
            nums1.push_back(n1[a]);
        }
        sort(nums1.begin(), nums1.end());
        for (int b = 0; b <= n; b++) {
            nums2.push_back(n2[b]);
        }
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        while (i <= n && j <= n) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] == nums2[j]) {
                if (common_elements.size() == 0 ||
                    common_elements.back() != nums1[i]) {
                    common_elements.push_back(nums1[i]);
                }
                i++;
                j++;
            } else {
                j++;
            }
        }
        return common_elements;
    }

public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> prefix_common_array;
        for (int i = 0; i < A.size(); i++) {
            prefix_common_array.push_back(common_array(A, B, i).size());
        }
        return prefix_common_array;
    }
};