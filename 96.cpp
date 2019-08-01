class Solution {
public:
    int numTrees(int n) {
        int g[n+1];
        
        g[0]= g[1]= 1;
        
        for( int i= 2; i<= n; ++i ) {
            g[i]= 0;
            
            for( int j= 0; j< i; ++j ) {
                g[i]+= g[j] * g[i-j-1];
            }
        }
        
        return g[n];
    }
};