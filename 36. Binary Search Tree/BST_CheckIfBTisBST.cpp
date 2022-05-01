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
    bool isBST(TreeNode* root, int min, int max){
        if(root == NULL){
            return true;
        }
        if(root->val > min and root->val < max){
            return isBST(root->left, min, root->val) and isBST(root->right, root->val, max);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root, INT_MIN, INT_MAX);
    }
};