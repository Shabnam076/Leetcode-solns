class Solution {
public:

    //optimal - O(1), O(1)
    int reverseBits(int n) {
        int result = 0;
        for(int i = 0; i < 32; i++){
            int lsb = n & 1;
            result = result << 1; //making slot for new lsb

            result = result | lsb; //will append lsb in res
            n = n >> 1;
        } 

        return result;
    }

    /*
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
    */
};