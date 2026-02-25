#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& arr){
        if(!root) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);

        int left = 0;
        int right = arr.size() - 1;

        while(left < right){
            int sum = arr[left] + arr[right];

            if(sum == k){
                return true;
            }
            else if(sum < k){
                left++;
            }
            else{
                right--;
            }
        }

        return false;
    }
};


// insert into BST
TreeNode* insertBST(TreeNode* root, int val){
    if(root == nullptr)
        return new TreeNode(val);

    if(val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}


int main(){
    int n, k;
    cin >> n;

    TreeNode* root = nullptr;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        root = insertBST(root, x);
    }

    cin >> k;

    Solution sol;
    bool result = sol.findTarget(root, k);

    if(result)
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}