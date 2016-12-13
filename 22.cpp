class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector< string > ans;
        generate( ans, "", n, n );
    
        return ans;
    }
    
    void generate( vector<string>& ans,  string s, int lcounter, int rcounter ){
        
        if( lcounter== 0 && rcounter== 0 ){
            ans.push_back( s );
            return;
        }
        
        if( lcounter > rcounter )
            return ;
        
        if( lcounter > 0 )
            generate( ans, s+"(", lcounter-1, rcounter );
        if( rcounter > 0 )
            generate( ans, s+")", lcounter, rcounter-1 );
        
    }
};