class Solution {
private:
    int start_idx(const vector<int>& nums, int x){
        int low = 0;
        int high = nums.size() - 1;
        int idx = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > x){
                high = mid - 1;
            }
            else if(nums[mid] == x){
                idx = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return idx;
    }

    int end_idx(const vector<int>& nums, int x){
        int low = 0;
        int high = nums.size() - 1;
        int idx = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > x){
                high = mid - 1;
            }
            else if(nums[mid] == x){
                idx = mid;
                low = mid + 1;
            }
            else{
                low = mid + 1;
            }
        }

        return idx;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {start_idx(nums, target), end_idx(nums, target)};
    }
};