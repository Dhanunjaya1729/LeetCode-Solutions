class Solution {
private:
    int traverse_right(vector<vector<int>>& matrix, int row_index,
                       int col_start, int col_end, int value) {
        for (int i = col_start; i <= col_end; i++) {
            value++;
            matrix[row_index][i] = value;
        }
        return value;
    }

    int traverse_down(vector<vector<int>>& matrix, int col_index, int row_start,
                      int row_end, int value) {
        for (int i = row_start; i <= row_end; i++) {
            value++;
            matrix[i][col_index] = value;
        }
        return value;
    }

    int traverse_left(vector<vector<int>>& matrix, int row_index, int col_start,
                      int col_end, int value) {
        for (int i = col_start; i >= col_end; i--) {
            value++;
            matrix[row_index][i] = value;
        }
        return value;
    }

    int traverse_up(vector<vector<int>>& matrix, int col_index, int row_start,
                    int row_end, int value) {
        for (int i = row_start; i >= row_end; i--) {
            value++;
            matrix[i][col_index] = value;
        }
        return value;
    }

public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int val = 0;

        int top = 0;
        int bottom = n - 1;

        int left = 0;
        int right = n - 1;

        while (left <= right && top <= bottom) {
            val = traverse_right(matrix, top, left, right, val);
            top++;

            val = traverse_down(matrix, right, top, bottom, val);
            right--;

            if (top <= bottom) {
                val = traverse_left(matrix, bottom, right, left, val);
                bottom--;
            }

            if (left <= right) {
                val = traverse_up(matrix, left, bottom, top, val);
                left++;
            }
        }

        return matrix;
    }
};