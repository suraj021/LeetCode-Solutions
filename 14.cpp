class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= (int)strs.size();
        
        if( n== 0 )
            return "";
        
        if( n== 1 )
            return strs[0];
        
        int l= INT_MAX;
        string base= strs[0];
        int m= (int) base.length();
        
        for( int i= 1; i < n; ++i ){
            string s= strs[i];
            int j= 0;
            
            for( int k= 0; k < (int)s.length() && k < base.length(); ++k ){
                if(  s[k]== base[k] ){
                    j++;
                }else{
                    break;
                }
            }
            
            l= min( l, j );
            
        }
        
        return base.substr( 0, l );
    }
};