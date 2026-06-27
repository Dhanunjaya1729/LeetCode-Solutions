class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long m = n * n;
        long long sum_m = (m * (m + 1)) / 2;
        long long sum_m_2 = (m * (m + 1) * (2 * m + 1)) / 6;

        long long sum = 0;
        long long sum_2 = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
                sum_2 += (grid[i][j] * grid[i][j]);
            }
        }

        long long val1 = sum - sum_m;
        long long val2 = sum_2 - sum_m_2;

        val2 = val2 / val1;

        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
};