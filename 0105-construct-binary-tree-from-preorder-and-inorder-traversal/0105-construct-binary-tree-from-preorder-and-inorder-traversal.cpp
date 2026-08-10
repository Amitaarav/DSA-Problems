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
    TreeNode* treeCreation(vector<int>& preorder, vector<int>& inorder, int& idx, int start, int end){

        if( start > end ) return NULL;

        int rootVal = preorder[idx];

        int i = start;
        for( ; i <= end; i++){
            if(inorder[i] == rootVal) {
                break;
            }
        }

        TreeNode* root = new TreeNode(rootVal);

        idx++;

        root->left = treeCreation(preorder, inorder, idx, start, i-1);
        root->right = treeCreation(preorder, inorder, idx, i + 1, end);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preSize = preorder.size();
        int idx = 0;

        return treeCreation(preorder, inorder, idx, 0, preSize - 1);
    }
};