class Solution {
private:
    bool bs(const vector<int>& nums, const int target){
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(matrix[mid][0] <= target && target <= matrix[mid].back()){
                return bs(matrix[mid], target);
            }
            else if(matrix[mid][0] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return false;
    }
};