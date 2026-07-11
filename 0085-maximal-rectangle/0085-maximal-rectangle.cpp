class Solution {
private:
    int largestRectangleArea(const vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = (st.empty()) ? -1 : st.top();
                maxArea = max(maxArea, element*(nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int element = heights[st.top()];
            st.pop();
            int nse = n;
            int pse = (st.empty()) ? -1 : st.top();
            maxArea = max(maxArea, element*(nse - pse - 1));
        }

        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                }
                else{
                    heights[j]++;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};