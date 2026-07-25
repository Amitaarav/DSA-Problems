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
    int maxValue(TreeNode* root, int & ans){
        auto left = 0;
        if(root->left) left = maxValue(root->left, ans);
        auto right = 0;
        if(root -> right) right = maxValue(root->right, ans);

        left = max(left, right);

        if(root->val >= left){
            ans++;
        }

        left = max(root->val, left);

        return left;
    }
    int countDominantNodes(TreeNode* root) {

        int ans = 0;
        maxValue(root, ans);
        return ans;
        
    }
};