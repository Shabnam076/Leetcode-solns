class Solution {
public:
    //optimal - O(n), O(n)
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> exist;

        for(int i = 0; i < n; i++){
            if(!exist.count(nums[i])) exist.insert(nums[i]);
            else return true;
        }

        return false;
    }

    /*
    //better - sorting and checking the adjacent - O(nlog n), O(1)
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]) return true;
        }

        return false;
    }
    */
    
};