class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n= (int)s.length();

        if( n== 1 )
            return 1;
            
        int ans= 0;

        int f= 1, b= 0;
        set<char> ss;

        ss.insert(s[0]);

        while( f < n ){
            pair< set<char>::iterator, bool > p= ss.insert( s[f] );
            if( p.second!= false ){
                int l= f-b+1;
                if( l > ans )
                    ans= l;
                f++;
            }else{
                ss.erase( s[b] );
                b++;
            }

        }

        return ans;
    }
};