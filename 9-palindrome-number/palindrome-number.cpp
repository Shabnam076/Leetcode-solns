class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        
        string rev = "";
        int ori = x;

        while(x){
            int rem = x % 10;
            rev += to_string(rem);

            x = x/10;
        }

        int reverse = stoll(rev);
        if(ori == reverse) return true;
        return false;
    }
};