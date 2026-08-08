class Solution {
public:
    //optimal - O(log2n),O(1)
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = INT_MAX;

        while(low <= high){
            int mid = (low + high)/2;
            //if left part is sorted [low ..... mid] , lowest = nums[low]
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else{ //right part is sorted [mid....high] , lowest = nums[mid]
                ans = min(ans, nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};