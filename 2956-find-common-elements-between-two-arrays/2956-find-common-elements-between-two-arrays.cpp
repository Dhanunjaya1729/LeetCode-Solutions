class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> common_elements;
        int i = 0;
        int j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] == nums2[j]) {
                if(common_elements.size() == 0 || common_elements.back() != nums1[i]){
                    common_elements.push_back(nums1[i]);
                }
                i++;
                j++;
            } else {
                j++;
            }
        }
        int answer1 = 0;
        int answer2 = 0;
        for(int x: common_elements){
            answer1 += count(nums1.begin(), nums1.end(), x);
        }
        for(int y: common_elements){
            answer2 += count(nums2.begin(), nums2.end(), y);
        }
        return {answer1, answer2};
    }
};