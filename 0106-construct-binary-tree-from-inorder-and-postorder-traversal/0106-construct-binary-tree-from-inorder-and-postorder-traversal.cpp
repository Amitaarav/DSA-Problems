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
    TreeNode* treeCreation(vector<int>& inorder, vector<int>& postorder, int& idx, int start, int end){
        if( start > end ) return NULL;

        int rootVal = postorder[idx];

        int i = start;
        for( ; i <= end; i++){
            if(inorder[i] == rootVal) {
                break;
            }
        }

        TreeNode* root = new TreeNode(rootVal);

        idx--;

        root->right = treeCreation(inorder, postorder, idx, i + 1, end);
        root->left = treeCreation(inorder, postorder, idx, start, i-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postSize = postorder.size();
        int idx = postSize - 1; // 

        return treeCreation(inorder, postorder, idx, 0, postSize - 1);
    }
};