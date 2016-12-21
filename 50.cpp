class Solution {
public:
    double myPow(double x, int n) {
        if( n== 0 )
            return 1.0;
        if( n== 1 )
            return x;
            
        if( n%2== 0 )
            return pow( x*x, n/2 );
        else
            return x*pow( x, n-1 );
    }
};