class Solution {
public: 
    void f(int i, vector<int> &ds,vector<vector<int>> &ans,int target, vector<int> &candidates){
        int n = candidates.size();
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        if(i == n) return;

        if(target >= candidates[i]){
            ds.push_back(candidates[i]);
            f(i,ds,ans,target - candidates[i],candidates);
            ds.pop_back();
        }

        f(i+1,ds,ans,target,candidates);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        if(n == 1 && candidates[0] == target)return {{candidates[0]}};
        vector<vector<int>> ans;

        vector<int> ds;
        f(0,ds,ans,target,candidates);
        return ans;
    }
};