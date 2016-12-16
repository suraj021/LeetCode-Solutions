class Solution {
public:
    int rob(vector<int>& nums) {
        int n= (int)nums.size();
        
        if( n==0 )
            return 0;
        if( n== 1 )
            return nums[0];
        
        int dp[n];
        //d[i] means the most value that can be robbed before the ith store
        dp[0]= nums[0];
        dp[1]= max( nums[1], dp[0] );
        
        for( int i= 2; i< n; ++i ){
            dp[i]= max( dp[i-2] + nums[i], dp[i-1] );
        }
        
        return dp[n-1];
    }
};