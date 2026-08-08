class Solution {
public:
    // optimal O(log n) , O(1)
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target) return mid;

            //left sorted - if target lies here then this is the range else target is right half
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target < nums[mid]){
                    high = mid - 1;
                }
                else low = mid+1;
            }
            //right sorted - if target lies here then this is the range else target in left half
            else{
                if(nums[mid] < target && target <= nums[high])low = mid+1;
                else high = mid-1;
            }
        }

        return -1;
    }
};