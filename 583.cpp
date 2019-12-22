class Solution {
public:
    int minDistance(string word1, string word2) {
        int m= word1.length();
        int n= word2.length();
        
        int dp[m+1][n+1];
        
        for(int i= 0; i<= m; ++i)
            dp[i][0]= i;
        for(int j= 0; j<= n; ++j)
            dp[0][j]= j;
        
        for(int i= 1; i<= m; ++i){
            for(int j= 1; j<= n; ++j){
                if(word1[i-1]== word2[j-1])
                    dp[i][j]= dp[i-1][j-1];
                else
                    dp[i][j]= 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        // return _minDistance(word1, word2, 0, 0);
        return dp[m][n];
    }
    
    int _minDistance(string w1, string w2, int i, int j){
        if(i == w1.length()) return w2.length() - j;
        if(j == w2.length()) return w1.length() - i;
        
        if(w1[i] == w2[j]) return _minDistance(w1, w2, i+1, j+1);
        
        return 1 + min(_minDistance(w1, w2, i+1, j), _minDistance(w1, w2, i, j+1));
    }
};