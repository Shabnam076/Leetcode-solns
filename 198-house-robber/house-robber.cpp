class Solution {
public:
    //Tabulation - O(n), O(n)

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);
        int cur = 0;
        for(int i = 2; i < n; i++){
            cur = max(nums[i] + prev2, prev1);

            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};



