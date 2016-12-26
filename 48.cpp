class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n= (int)a.size();
        
        if( n== 0 )
            return ;
            
        for( int i= 0; i< n/2; ++i ){
            for( int j= i; j< n-1-i; ++j ){
                int t= a[n-1-j][i];
                a[n-1-j][i]= a[n-1-i][n-1-j];
                a[n-1-i][n-1-j]= a[j][n-1-i];
                a[j][n-1-i]= a[i][j];
                a[i][j]= t;
            }
        }
        
        return ;
    }
};