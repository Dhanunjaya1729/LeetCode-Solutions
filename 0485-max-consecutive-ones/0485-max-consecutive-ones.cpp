class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current_max = 0;
        int maximum = 0;
        for(const int& x: nums){
            if(x == 1){
                current_max++;
                maximum = max(current_max, maximum);
            }
            else{
                current_max = 0;
            }
        }
        return maximum;
    }
};