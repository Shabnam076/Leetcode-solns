class Solution {
public:
    
    //Follow up - divide and conquer
    //Tc - O(nlogn), sc - o(nlogn)
    int DC(int l, int r,vector<int> &nums){
        if(l == r)return nums[l];   //base case

        int mid = (l+r)/2;
        int left = DC(l,mid,nums);  //will return sum of left array
        int right = DC(mid+1,r,nums);  //will return sum of right array

        int leftSum = INT_MIN;
        int sum = 0;

        for(int i = mid; i >= l; i--){
            sum += nums[i];
            leftSum = max(leftSum,sum);
        }
        sum = 0;
        int rsum = INT_MIN;

        for(int i = mid+1; i <= r; i++){
            sum += nums[i];
            rsum = max(rsum,sum);
        }
        int midsum = leftSum + rsum;

        return max(left,max(right,midsum));
    }

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        return DC(0,n-1,nums);
    }

    /*
    // Kadanes algo - O(n), O(1)
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int maxSum = INT_MIN;  //imp - dont intialize with 0 coz of such cases : [-2,-3,-5]
        for(int i = 0; i < n; i++){
            sum += nums[i];
            maxSum = max(maxSum,sum);

            if(sum < 0) sum = 0;
        }
        return maxSum;  
    }
    */
};