class Solution {
public:
    int digits(int num){
        int cnt = 0;
        while(num){
            int rem = num % 10;
            cnt++;
            num = num/10;
        }
        return cnt;
    }
    vector<int> sequentialDigits(int low, int high) {
        
        string s = "123456789";
        int l = digits(low);
        int h = digits(high);

        vector<int> ans;

        for(int i = l; i <= h; i++){
            for(int j = 0; j <= 9-i; j++){
                string st = s.substr(j,i);
                int num = stoi(st);
                if(num > high)break;
                else if(num < low) continue;
                else ans.push_back(num);
            }
        }
        return ans; 
    }
};