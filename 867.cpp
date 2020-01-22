class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m= A.size();
        int n= A[0].size();
        vector<vector<int>> B(n, vector<int>(m));
        
        for(int i= 0; i< n; ++i){
            for(int j= 0; j< m; ++j){
                B[i][j]= A[j][i];
            }
        }
        
        return B;
    }
};