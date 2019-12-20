class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        
        if(n<= 2)
            return true;
        pair<int,int> dp[n][n];
        
        int d= 0;
        
        while(d < n){
            int i= 0, j= d;
            
            while(i< n && j< n){
                if(i == j){
                    dp[i][j].first= piles[i];
                    dp[i][j].second= 0;
                } else if(piles[j] + dp[i][j-1].second > piles[i] + dp[i+1][j].second){
                    dp[i][j].first= piles[j] + dp[i][j-1].second;
                    dp[i][j].second= dp[i][j-1].first;
                } else {
                    dp[i][j].first= piles[i] + dp[i+1][j].second;
                    dp[i][j].second= dp[i+1][j].first;
                }
                i++; j++;
            }
            d++;
        }
        
        return dp[n-1][n-1].first > dp[n-1][n-1].second;
    }
};