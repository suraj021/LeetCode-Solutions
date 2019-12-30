class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        return minDistanceRecursive(0, 0, word1, word2, dp);
    }
    
    int minDistanceRecursive(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(i == word1.length()) return word2.length()-j;
        if(j == word2.length()) return word1.length()-i;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int res;
        
        if(word1[i] == word2[j]){
            res= minDistanceRecursive(i+1, j+1, word1, word2, dp);
        } else {
            int replaceL= minDistanceRecursive(i+1, j+1, word1, word2, dp);
            int insertL= minDistanceRecursive(i, j+1, word1, word2, dp);
            int deleteL= minDistanceRecursive(i+1, j, word1, word2, dp);
            
            res= 1 + min(replaceL, min(insertL, deleteL));
        }
        
        return dp[i][j] = res;
    }
    
    int minDistanceIterative(string word1, string word2){
        int m= word1.size();
        int n= word2.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i= 1; i<= m; ++i){
            dp[i][0]= i;
        }
        
        for(int j= 1; j<= n; ++j){
            dp[0][j]= j;
        }
                
        for(int i= 1; i<= m; ++i){
            for(int j= 1; j<= n; ++j){
                if(word1[i-1] == word2[j-1])
                    dp[i][j]= dp[i-1][j-1];
                else
                    dp[i][j]= 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
        
        return dp[m][n];
    }
};