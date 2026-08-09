class Solution {
public:
    //Optimal : 
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);

        for(int i = 0; i < n+1; i++){
            if(i % 2 == 0) ans[i] = ans[i/2];
            else ans[i] = ans[i/2] + 1;
        } 

        return ans;
    }

    /*
    //Better - O(nlog n), O(1)
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);

        for(int i = 1; i < n+1; i++){
            int num = i;
            int cnt = 0;
            while(num){
                cnt++;
                num = (num & (num-1));
            }
            ans[i] = cnt;
        } 

        return ans;
    }
    */
    
    /*
    //Brute force : O(nlogn), O(1) excluding ans array
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);

        for(int i = 1; i < n+1; i++){
            int num = i;
            int cnt = 0;
            while(num){
                if(num & 1)cnt++;
                num = num >> 1;
            }
            ans[i] = cnt;
        } 
        return ans;
    }
    */
};