class Solution {
public:

    bool odd(vector<int> &nums1){
        int n = nums1.size();

        vector<bool> pre(n,0);
        vector<bool> suf(n,0);

        for(int i = 1; i < n; i++){
            bool u = (pre[i-1] || (nums1[i-1] % 2 == 1));
            pre[i] = u; 
        }
        for(int i = n-2; i >= 0; i--){
            bool u = (suf[i+1] || (nums1[i+1] % 2 == 1));
            suf[i] = u;
        }

        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 == 1) continue;
            if(!(pre[i] || suf[i])) return false;
        }

        return true;

    }

    bool even(vector<int> &nums1){
        int n = nums1.size();

        vector<bool> pre(n,0);
        vector<bool> suf(n,0);

        for(int i = 1; i < n; i++){
            bool u = (pre[i-1] || (nums1[i-1] % 2 == 0));
            pre[i] = u; 
        }
        for(int i = n-2; i >= 0; i--){
            bool u = (suf[i+1] || (nums1[i+1] % 2 == 0));
            suf[i] = u;
        }

        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 == 0) continue;
            if(!(pre[i] || suf[i])) return false;
        }

        return true;
    }

    bool uniformArray(vector<int>& nums1) {
        bool u = odd(nums1);
        if(u) return true;
        return even(nums1);  
    }
};