class Solution {
public:
    //optimal - two ponter O(n),O(1)
    int maxArea(vector<int>& height) {
        int n = height.size();

        int maxw = 0;
        int l = 0, r = n-1;
        while(l < r){
            int len = r-l;
            int hei = min(height[r],height[l]);
            maxw = max(maxw, len*hei);

            if(height[l] <= height[r]) l++;
            else r--;
        }

        return maxw;
    }

    /*
    //brute force - O(n2), O(1)
    int maxArea(vector<int>& height) {
        int n = height.size();

        int maxW = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int len = j-i;
                int hei = min(height[i],height[j]);
                maxW = max(maxW, len*hei);
            }
        }

        return maxW; 
    }
    */
};