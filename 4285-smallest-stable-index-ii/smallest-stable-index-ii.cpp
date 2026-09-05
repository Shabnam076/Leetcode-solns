class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> prefixMax(n,0);
        vector<int> suffixMin(n,1e8);
        suffixMin[n-1] = nums[n-1];
        prefixMax[0] = nums[0];

        for(int i = 1; i < n; i++){
            prefixMax[i] = max(prefixMax[i-1],nums[i]);
        }

        for(int i = n-2; i >= 0; i--){
            suffixMin[i] = min(suffixMin[i+1],nums[i]);
        }

        int index = -1;
        for(int i = 0; i < n; i++){
            int instability_score = prefixMax[i] - suffixMin[i];
            if(instability_score <= k) return i;
        }

        return index;
        
    }
};