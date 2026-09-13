class Solution {
public:
    void f(int ind, vector<int>& candidates, int target,
           vector<vector<int>>& ans, vector<int>& curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > target)
                break;
            curr.push_back(candidates[i]);
            f(i + 1, candidates, target - candidates[i], ans, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        f(0, candidates, target, ans, curr);
        return ans;
    }
};