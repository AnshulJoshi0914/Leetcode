class Solution {
public:
    void f(vector<int>& candidates, int target, int ind,
           vector<int>& curr, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        if(ind == candidates.size() || target < 0) {
            return;
        }
        curr.push_back(candidates[ind]);
        f(candidates, target - candidates[ind], ind, curr, ans);
        curr.pop_back();
        f(candidates, target, ind + 1, curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        f(candidates, target, 0, curr, ans);
        return ans;
    }
};