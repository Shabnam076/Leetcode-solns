class Solution {
public:
    int reverseBits(int n) {
        vector<int> ans(32,0);
        int i = 0;
        while(n){
            int rem = n % 2; //lsb
            ans[i] = rem;
            i++;
            n = n >> 1;
        }

        long long mul = 1;
        int num = 0;
        for(int i = ans.size()-1; i >= 0; i--){
            num += (mul* ans[i]);
            mul *= 2;
        }
        return num;
        
    }
};