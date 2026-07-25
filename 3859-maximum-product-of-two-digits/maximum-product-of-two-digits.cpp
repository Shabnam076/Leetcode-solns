class Solution {
public:
    int maxProduct(int n) {
        vector<int> num;
        while(n){
            int rem = n % 10;
            num.push_back(rem);

            n = n/10;
        }

        sort(num.begin(),num.end());
        int m = num.size();

        return num[m-2]*num[m-1];   
    }
};