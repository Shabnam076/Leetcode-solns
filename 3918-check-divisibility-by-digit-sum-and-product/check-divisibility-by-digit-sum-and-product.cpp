class Solution {
public:
typedef long long ll;
    bool checkDivisibility(int n) {
        int orig = n;
        ll sum = 0;
        ll product = 1;

        while(n){
            int rem = n % 10;
            sum += rem;
            product *= rem;

            n /= 10;
        }

        ll total = sum + product;

        return (orig % total == 0) ? 1 : 0;
        
    }
};