class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int,int>> vt;
        for(int i = 0; i < n; i++){
            vt.push_back({nums[i],i});
        }
        sort(vt.begin(),vt.end());

        int l = 0, h = n-1;

        while(l < h){
            auto num1 = vt[l].first;
            auto num2 = vt[h].first;
            long long sum = (long long)num1 + num2;
            if(sum == target) return {vt[l].second,vt[h].second};
            else if(sum < target) l++;
            else h--;
        }

        return {};
    }
    
};