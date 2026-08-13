class Solution {
public:
    int maxmoney(vector<int>& temp) {
        int n = temp.size();
        if(n == 1)return temp[0];

        int prev2 = temp[0];
        int prev1 = max(temp[0],temp[1]);
        int cur = 0;
        for(int i = 2; i < n; i++){
            cur = max(temp[i] + prev2, prev1);

            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n== 1)return nums[0];
        if(n == 2)return max(nums[0],nums[1]);
        
        vector<int> temp1(n-1,0),temp2(n-1,0);

        for(int i = 0; i < n; i++){
            if(i != 0) temp1[i-1] = nums[i];
            if(i != n-1)temp2[i] = nums[i];
        }
        int one = maxmoney(temp1);
        int two = maxmoney(temp2);

        return max(one, two);
    }
};