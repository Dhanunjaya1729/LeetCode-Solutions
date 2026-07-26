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
    int dfsheight(TreeNode* node){
        if(node == nullptr) return 0;

        int l_h = dfsheight(node->left);
        if(l_h == -1) return -1;

        int r_h = dfsheight(node->right);
        if(r_h == -1) return -1;

        if(abs(l_h - r_h) > 1) return -1;
        return max(l_h, r_h) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfsheight(root) != -1;
    }
};