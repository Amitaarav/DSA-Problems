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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }

        // if root value is already equal to key then we have to delete root
        // if we need to delete the root, use dummy tree root
        if(root->val == key){
            return helper(root);// 
        }

        TreeNode* dummyTree = root;

        while(root != NULL){
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                }else{
                    root = root->left;
                }
            }else{
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                }else{
                    root = root->right;
                }
            }
        }
        return dummyTree;
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }

        if(root->right == NULL){
            return root->left;
        }

        TreeNode* rightChild = root->right; // Keep right side as another entity which later will be attached to the root

        TreeNode* lastRight = findLastRight(root->left); // It helps in finding the right most element/node which would be just lesser than rightChild root

        lastRight->right = rightChild; // atached rightChild to the lastMost right node

        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL){
            return root;
        }

        return findLastRight(root->right);
    }
};