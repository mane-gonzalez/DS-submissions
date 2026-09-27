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
public:
    int goodNodes(TreeNode* root) {
        int result = 0;
        helper(root, result, root->val);
        return result;
    }

    void helper(TreeNode* node, int &result, int maxVal) {
        if(!node)
            return;
        
        if(node->val >= maxVal)
            result++;

        helper(node->left,  result, max(maxVal, node->val));
        helper(node->right, result, max(maxVal, node->val));
    }
};
