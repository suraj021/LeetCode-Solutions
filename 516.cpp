class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n= (int)s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        
        // int dp[n][n];
        
        for (int i = n-1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
        // return lps(0, n-1, s, dp);
    }
    
    int lps(int i, int j, string& s, vector<vector<int>>& dp){
        if(i > j) return 0;
        if(i == j) return 1;
        
        if(dp[i][j])    return dp[i][j];
        
        dp[i][j]= (s[i]== s[j]) ? 2+lps(i+1, j-1, s, dp) : max( lps(i, j-1, s, dp), lps(i+1, j, s, dp));
        
        return dp[i][j];
    }
};