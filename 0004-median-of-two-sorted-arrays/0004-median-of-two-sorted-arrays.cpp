class Solution {
private:
    vector<int> mergedArray(const vector<int>& n1, const vector<int> n2){
        vector<int> merged_array;
        int i = 0;
        int j = 0;
        while(i < n1.size() && j < n2.size()){
            if(n1[i] < n2[j]){
                merged_array.push_back(n1[i]);
                i++;
            }
            else if(n1[i] == n2[j]){
                merged_array.push_back(n1[i]);
                merged_array.push_back(n2[j]);
                i++;
                j++;
            }
            else{
                merged_array.push_back(n2[j]);
                j++;
            }
        }
        while(i < n1.size()){
            merged_array.push_back(n1[i]);
            i++;
            }
        while(j < n2.size()){
            merged_array.push_back(n2[j]);
            j++;
        }
        return merged_array;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num = mergedArray(nums1, nums2);
        int n = num.size();
        if(n % 2 != 0){
            return num[n/2];
        }
        else{
            return (double(num[n/2] + num[n/2 - 1]))/2;
        }
    }
};