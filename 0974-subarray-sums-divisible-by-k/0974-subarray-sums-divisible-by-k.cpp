class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        vector<int> rem_count(k, 0);
        rem_count[0] = 1;
        int cur_sum = 0;

        for(int num: nums){
            cur_sum += num;
            int rem = ((cur_sum % k) + k) % k;
            count += rem_count[rem];
            rem_count[rem]++;
        }

        return count;
    }
};