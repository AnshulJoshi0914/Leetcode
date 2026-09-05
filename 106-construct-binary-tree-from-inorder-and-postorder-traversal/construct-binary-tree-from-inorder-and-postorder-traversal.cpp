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

   TreeNode* build(vector<int>& inorder,vector<int>& postorder,int is,int ie,int ps,int pe,map<int,int>& mpp){
    if(is>ie||ps>pe) return nullptr;
    TreeNode* root = new TreeNode(postorder[pe]);
    int inRoot=mpp[postorder[pe]];
    int numsleft=inRoot-is;
    root->left=build(inorder,postorder,is,inRoot-1,ps,ps+numsleft-1,mpp);
    root->right=build(inorder,postorder,inRoot+1,ie,ps+numsleft,pe-1,mpp);
    return root;
   }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
         map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,mpp);
    }
};