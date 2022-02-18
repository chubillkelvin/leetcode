class Solution {
    int n, target;
    vector<int> candidates;
    vector <vector<int>> ans;
public:
    void dfs(vector<int> &candidates, vector<int> &temp) {
        int sum = 0;
        for (int num: temp) sum += num;
        for (int i = 0; i < n; i++) {
            int curr = candidates[i];
            if (!temp.empty() && curr < temp.back()) continue;
            temp.push_back(curr);
            if (sum + curr == target) {
                ans.push_back(temp);
            } else if (sum + curr < target) {
                dfs(candidates, temp);
            }
            temp.pop_back();
        }
    }

    vector <vector<int>> combinationSum(vector<int> &candidates, int target) {
        this->n = candidates.size();
        this->target = target;
        vector<int> temp;
        dfs(candidates, temp);
        return ans;
    }
};