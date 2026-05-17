class Solution {
private:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal_triangle;
        for(int i = 0; i < numRows; i++){
            vector<int> temp;
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    temp.push_back(1);
                }
                else{
                    temp.push_back(pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j]);
                }
            }
            pascal_triangle.push_back(temp);
        }
        return pascal_triangle;
    }
public:
    vector<int> getRow(int rowIndex) {
        return generate(rowIndex + 1)[rowIndex];
    }
};