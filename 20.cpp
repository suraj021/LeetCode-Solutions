class Solution {
public:
    bool isValid(string s) {
        int n= (int)s.length();
        
        if( n%2== 1 )
            return false;
        
        stack< char > st;
        
        for( int i= 0; i< n; ++i ){
            if( s[i]== '(' || s[i]== '{' || s[i]== '[' ){
                st.push( s[i] );
            }else{
                if( st.empty() )
                    return false;
                else{
                    char c= st.top();
                    st.pop();
                
                    if( c== '(' && s[i]!= ')' )
                        return false;
                    if( c== '{' && s[i]!= '}' )
                        return false;
                    if( c== '[' && s[i]!= ']' )
                        return false;
                }
            }
        }
        
        if( !st.empty() )
            return false;
        
        return true;
    }
};