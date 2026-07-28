/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int findMaxPathSum(TreeNode*node, int& maxi){
        if(node == nullptr) return 0;

        int leftMaxPath = max(0, findMaxPathSum(node->left, maxi));
        int rightMaxPath = max(0, findMaxPathSum(node->right, maxi));
        maxi = max(maxi, leftMaxPath + rightMaxPath + node->val);
        return max(leftMaxPath, rightMaxPath) + node->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findMaxPathSum(root, maxi);
        return maxi;
    }
};