class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int ans= 0;
        int i= 0, n= nums.size();
        
        while(i < n){
            int c= 1, j= i+1;
            while(j < n && nums[j] > nums[j-1]){
                c++;
                j++;
            }

            ans= max(ans, c);
            i= j;
        }
        
        return ans;
    }
};