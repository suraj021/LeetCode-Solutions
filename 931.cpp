class Solution {
public:
    
    bool isValid(int i, int j, int m, int n){
        return i>=0 && i<m && j>=0 && j<n;    
    }
    
    int minFallingPathSum(vector<vector<int>>& A) {
        int m= A.size();
        int n= A[0].size();
        
        for(int i= 1; i< m; i++){
            for(int j= 0; j< n; ++j){
                int mini= INT_MAX;
                if( isValid(i-1, j-1, m, n) ){
                    mini= min(mini, A[i-1][j-1]);
                }
                if( isValid(i-1, j+1, m, n) ){
                    mini= min(mini, A[i-1][j+1]);
                }
                mini= min(mini, A[i-1][j]);
                A[i][j]+= mini;
            }
        }
        
        int ans= INT_MAX;
        
        for(int j= 0; j< n; ++j){
            ans= min(ans, A[m-1][j]);
        }
        
        return ans;
    }
};