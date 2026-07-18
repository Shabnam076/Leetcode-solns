class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = 0;

        for(int i = 0; i < n; i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }

        while(mini != 0 && maxi != 0){
            if(maxi >= mini)maxi = maxi % mini;
            else mini = mini % maxi;
        }

        return maxi == 0 ? mini : maxi;
        
    }
};