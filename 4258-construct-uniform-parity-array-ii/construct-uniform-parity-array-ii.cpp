class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        
        bool u = true;  //all even
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 == 1) u = false;
            mini = min(mini,nums1[i]);
        }
        if(u) return true;
        if(mini % 2 == 0)return false;
        return true;
    }
};