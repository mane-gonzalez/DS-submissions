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
    bool isBalanced(TreeNode* root) {
        bool result = true;

        helper(root, result);

        return result;
        
    }

    int helper(TreeNode *root, bool &result){
        if(!root)
            return 0;

        int left = helper(root->left, result);
        int right = helper(root->right, result);

        if(abs(left - right) > 1)
            result = false;

        return 1 + max(left, right);
    }
};
