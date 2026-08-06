class Solution {
public:
    //optimal - O(n), O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int prefix = 1;
        vector<int> ans(n,0);
        for(int i = 0; i < n; i++){
            ans[i] = prefix;

            prefix *= nums[i];
        }

        int suffix = 1;
        for(int i = n-1; i >= 0; i--){
            ans[i] *= suffix;

            suffix *= nums[i];
        }
        return ans;
    }

    /*
    // better - O(n), O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n,1), suf(n,1);
        pre[0] = nums[0] , suf[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--){
            suf[i] = suf[i+1]*nums[i];
        }

        vector<int> ans(n,0);
        ans[0] = suf[1];
        for(int j = 1; j < n; j++){
            pre[j] = pre[j-1]* nums[j];
            if(j != n-1) ans[j] = pre[j-1]*suf[j+1];
        }
        ans[n-1] = pre[n-2];
        return ans;
    }
    */

    /*
    brute - O(n^2), O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n,1);

        for(int i = 0; i < n; i++){
            int product = 1;
            for(int j = 0; j < n; j++){
                if(j != i) product *= nums[j];
            }
            ans[i] = product;
        }

        return ans;
    }
    */

};