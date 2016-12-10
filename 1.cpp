class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n= (int)nums.size();
        int x, y;
        
        for( int i= 0; i< n; ++i ){
            for( int j= i+1; j < n; ++j ){
                if( nums[i]+nums[j]== target ){
                    x= i;
                    y= j;
                    break;
                }
            }
        }
        
        vector<int> ans( {x, y} );
        
        return ans;
        
    }
};