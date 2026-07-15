class Solution {
public:
    int gcd(int e, int o){
        while(e != 0 && o != 0){
            if(e > o){
                e = e % o;
            }
            else o = o % e;
        }
        return e == 0 ? o : e;
    }

    int gcdOfOddEvenSums(int n) {
        if(n == 1)return 1;
        
        int sum = -1;
        int oddsum = 0;
        for(int odd = 0; odd < n; odd++){
            sum += 2;
            oddsum += sum;
        }

        int sm = 0,evensum = 0;;
        for(int even = 0; even < n; even++){
            sm += 2;
            evensum += sm;
        }

        int ans = gcd(evensum,oddsum);

        return ans;

    }
};