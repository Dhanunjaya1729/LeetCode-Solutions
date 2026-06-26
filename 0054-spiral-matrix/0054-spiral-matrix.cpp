class Solution {
private:
    void traverse_right(const vector<vector<int>>& matrix,
                        vector<int>& spiral_order, int row_index, int col_start,
                        int col_end) {
        for (int i = col_start; i <= col_end; i++) {
            spiral_order.push_back(matrix[row_index][i]);
        }
    }

    void traverse_down(const vector<vector<int>>& matrix,
                       vector<int>& spiral_order, int col_index, int row_start,
                       int row_end) {
        for (int i = row_start; i <= row_end; i++) {
            spiral_order.push_back(matrix[i][col_index]);
        }
    }

    void traverse_left(const vector<vector<int>>& matrix,
                       vector<int>& spiral_order, int row_index, int col_start,
                       int col_end) {
        for (int i = col_start; i >= col_end; i--) {
            spiral_order.push_back(matrix[row_index][i]);
        }
    }

    void traverse_up(const vector<vector<int>>& matrix,
                     vector<int>& spiral_order, int col_index, int row_start,
                     int row_end) {
        for (int i = row_start; i >= row_end; i--) {
            spiral_order.push_back(matrix[i][col_index]);
        }
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m - 1;

        int left = 0;
        int right = n - 1;

        vector<int> spiral_order;

        while (left <= right && top <= bottom) {
            traverse_right(matrix, spiral_order, top, left, right);
            top++;

            traverse_down(matrix, spiral_order, right, top, bottom);
            right--;

            if (top <= bottom) {
                traverse_left(matrix, spiral_order, bottom, right, left);
                bottom--;
            }

            if (left <= right) {
                traverse_up(matrix, spiral_order, left, bottom, top);
                left++;
            }
        }

        return spiral_order;
    }
};