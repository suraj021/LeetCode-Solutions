class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int m= s.length();
        int n= t.length();
        
        int dp[m+1][n+1];
        
        for( int i= 0; i<= m; ++i ) dp[i][0]= 0;
        for( int j= 0; j<= n; ++j ) dp[0][j]= 0;
        
        for( int i= 1; i<= m; ++i ){
            for( int j= 1; j<= n; ++j ) {
                if( s[i-1]== t[j-1] ){
                    dp[i][j]= 1 + dp[i-1][j-1];
                } else {
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
};