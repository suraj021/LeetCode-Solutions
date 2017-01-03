class Solution {
public:
    int lengthOfLastWord(string s) {
        int n= (int)s.length();
        
        if( n== 0 )
            return 0;
        int i= n-1;
        
        while( s[i]== ' ' )
            i--;
        
        int j= i;
        
        for( ; i>= 0; --i ){
            if( s[i]== ' ' )
                break;
        }
        return j-i;
    }
};