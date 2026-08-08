class Solution {
public:
    //Optimal - BS, avg tc = O(log n) WOrst - O(N), coz of [1,1,1,1,1]
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MAX;
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[low] == nums[high])
            {
                ans = min(ans , nums[low]);
                high--;
                continue;
            }

            if(nums[low] <= nums[high]){
                ans = min(ans,nums[low]);
                break;
            }
            //left is sorted
            else if(nums[low] <= nums[mid]){
                ans = min(ans,nums[low]);
                low = mid + 1;
            } //right is sorted
            else{
                ans = min(ans,nums[mid]);
                high = mid-1;

            }    
        }
        return ans;
        
    }
};