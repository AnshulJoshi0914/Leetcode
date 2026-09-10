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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LLONG_MIN,LLONG_MAX);
    }


    bool isValidBST(TreeNode* root,long long valMin,long long valMax){
        if(root==nullptr) return true;

        if(root->val<=valMin||root->val>=valMax){
            return false;
        }
        return isValidBST(root->left,valMin,root->val)&&isValidBST(root->right,root->val,valMax);
    }
};