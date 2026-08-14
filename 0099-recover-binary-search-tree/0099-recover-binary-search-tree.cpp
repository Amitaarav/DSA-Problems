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
    void inorder(TreeNode* root, vector<TreeNode*> &nodes){
        if(root == NULL) return;

        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);

        int n = nodes.size();

        TreeNode* firstNode = NULL;
        TreeNode* secondNode = NULL;

        for(int i = 0; i + 1 < n; i++){
            if(nodes[i]->val > nodes[i + 1]->val){
                if(firstNode == NULL) {
                    firstNode = nodes[i];
                    secondNode = nodes[i + 1];
                }else{
                    secondNode = nodes[i + 1];
                }
            }
        }
        swap(firstNode->val, secondNode->val);
    }
};