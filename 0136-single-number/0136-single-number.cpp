class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR = 0;
        for (int x : nums) {
            XOR = XOR ^ x;
        }
        return XOR;
    }
};