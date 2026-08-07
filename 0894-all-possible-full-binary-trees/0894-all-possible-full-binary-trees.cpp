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
    unordered_map<int, vector<TreeNode*>> mp;

    vector<TreeNode*> helper(int n){
        if(n % 2 == 0) return {};

        if(n == 1) {
            TreeNode* root = new TreeNode(0);
            return {root};
        }

        vector<TreeNode*> result;

        for(int i = 1; i < n; i+= 2){
            vector<TreeNode*> leftBT = helper(i);
            vector<TreeNode*> rightBT = helper(n - i - 1);

            for(auto &l : leftBT){
                for(auto &r : rightBT){
                    TreeNode* root = new TreeNode(0);
                    root->left  = l;
                    root->right = r;

                    result.push_back(root);
                }
            }
        }

        return mp[n] = result;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        return helper(n);
    }
};