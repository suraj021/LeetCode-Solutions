class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string keys[]= { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector< string > ans;
        int n= digits.length(), level= 0;
        string s= "";
        
        if( n== 0 )
            return ans;
        
        solution( ans, keys, digits, level, n, s );
        
        return ans;
    }
    
    void solution( vector<string> &ans, string keys[], string digits, int level, int n, string &s ){
        
        if( level== n ){
            ans.push_back( s );
            return ;
        }   
        
        int x= digits[level] - '0';
        
        for( int i= 0; i< keys[x].length(); ++i ){
            s= s + keys[x][i];
            solution( ans, keys, digits, level+1, n, s );
            s.pop_back();
        }
    }
};