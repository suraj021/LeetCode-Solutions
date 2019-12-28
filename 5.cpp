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

    // O(n^2) method which is extension of counting of palindromic substrings in a string
    string _longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        
        int ans= 1;
        int n= (int)s.length();
        int start, end;
        start= end= 0;

        for(int i= 0; i< n; ++i){
            // cout << start << " " << end << " after: " ;
            for(int l= i, r= i; l>= 0 && r< n && s[l] == s[r]; --l, ++r){
                if(r-l+1 > ans){
                    ans= r-l+1;
                    start= l; end= r;
                }
            }
            for(int l= i, r= i+1; l>= 0 && r < n && s[l] == s[r]; --l, ++r){
                if(r-l+1 > ans){
                    ans= r-l+1;
                    start= l; end= r;
                }
            }
            
            // cout << start << " " << end << endl;
        }
        
        return s.substr(start, end-start+1);
    }
};