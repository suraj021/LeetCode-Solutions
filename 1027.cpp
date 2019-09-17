class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n= (int)A.size();
        int ans= 0;
        vector<map<int, int>> dp(n);
        
        for(int i= 0; i< n; ++i){
            for(int j= 0; j< i; ++j){
                int d= A[i] - A[j];
                dp[i][d]= dp[j][d] ? dp[j][d] + 1 : 2;
                ans= max(ans, dp[i][d]);
            }
        }
        
        return ans;
    }
};