class Solution {
public:
    //Optimal - O(n²) time and O(1)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            //two pointers
            int j = i+1 , k = n-1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1])k--;

                }

                else if(nums[i] + nums[j] + nums[k] < 0) j++;
                else{
                    k--;
                }

            }
        }
        return ans;
    }

    /*
    //Better - O(n^2 log M), Sc - O(n) + 2*(no of unique ele)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>> st;  // for storing unique triplets
        for(int i = 0; i < n; i++){
            set<int> hash;
            for(int j = i+1; j < n; j++){
                int need = -(nums[i] + nums[j]);
                if(hash.find(need) != hash.end()){   //need is present
                    vector<int> temp = {nums[i],nums[j],need};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }

                hash.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
    */
};