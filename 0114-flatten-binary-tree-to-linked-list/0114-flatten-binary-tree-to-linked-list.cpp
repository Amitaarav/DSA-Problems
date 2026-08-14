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
    TreeNode* dummy;
    TreeNode* tail;

    void preOrder(TreeNode* root){
        if(root == NULL) {
            return ;
        }

        auto newNode = new TreeNode(root->val);
        tail = newNode;

        preOrder(root->left);
        preOrder(root->right);
    }

    void flatten(TreeNode* root) {
        // dummy = new TreeNode (-1);
        // preOrder(root);
        // return dummy->right;

        if(root == NULL) return;

        flatten(root->right);
        flatten(root->left);

        root->right = tail;
        root->left = NULL;

        tail = root;

    }
};