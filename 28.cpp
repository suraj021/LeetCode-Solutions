class Solution {
public:
    int strStr(string haystack, string needle) {
        int m= haystack.length();
        int n= needle.length();
        
        if( n== 0 )
            return 0;
        
        vector<int> lps = calculateLPS(needle);
        
        int i= 0, j=0;
        while( i < m ) {
            if( haystack[i] == needle[j] ) {
                i++; j++;
                
                if( j== n ) {
                    return ( i-j );
                }
            } else {
                if( j!= 0 ) {
                    j= lps[j-1];
                } else {
                    i+= 1;
                }
            }
        }
        return -1;
    }
    
    vector<int> calculateLPS(string s) {
        int n= s.length();
        vector<int> lps(n);
        
        lps[0]= 0;
        int i= 0, j= 1;
        
        while( j < n ) {
            if( s[j] == s[i] ) {
                lps[j]= i+1;
                j++; i++;
            } else {
                if( i!= 0 ) {
                    i= lps[i-1];
                } else {
                    lps[j] = 0;
                    j++;
                }
            }
        }
        return lps;
    }
};