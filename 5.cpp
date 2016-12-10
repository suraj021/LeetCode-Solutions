class Solution {
public:
    string longestPalindrome(string s) {
        
        int n= (int)s.length();
        
        if( n== 1 )
            return s;
        
        bool dp[n][n];
        
        memset( dp, false, sizeof dp );
        
        int len= 1, id;
        
        for( int i= 0; i< n; ++i ){
            dp[i][i]= true;
        }
        
        // for palindrome of length 2
        for( int i= 0; i< n-1; ++i ){
            if( s[i]== s[i+1] ){
                dp[i][i+1]= true;
                len= 2;
                id= i;
            }else
                dp[i][i+1]= false;
        }
        
        for( int l= 3; l<= n; ++l ){
            for( int i= 0; i< n-l+1; ++i ){
                int j= i+l-1;
                if( dp[i+1][j-1] && s[i]== s[j] ){
                    dp[i][j]= true;
                    if( l > len ){
                        id= i;
                        len= l;
                    }
                }
            }
        }
        
        return s.substr( id, len );
    }
};