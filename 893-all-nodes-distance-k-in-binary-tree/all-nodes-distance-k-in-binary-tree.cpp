
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    void markparents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parents_track) {

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if(current->left) {
                parents_track[current->left] = current;
                q.push(current->left);
            }

            if(current->right) {
                parents_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parents_track;
        markparents(root, parents_track);

        unordered_map<TreeNode*, bool> vis;

        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;

        int curr_level = 0;

        while(!q.empty()) {
            if(curr_level == k)
                break;

            int size = q.size();

            for(int i = 0; i < size; i++) {

                TreeNode* current = q.front();
                q.pop();

                
                if(current->left && !vis[current->left]) {
                    q.push(current->left);
                    vis[current->left] = true;
                }

               
                if(current->right && !vis[current->right]) {
                    q.push(current->right);
                    vis[current->right] = true;
                }

            
                if(parents_track[current] &&
                   !vis[parents_track[current]]) {

                    q.push(parents_track[current]);
                    vis[parents_track[current]] = true;
                }
            }

            curr_level++;
        }

       
        vector<int> res;

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            res.push_back(curr->val);
        }

        return res;
    }
};

