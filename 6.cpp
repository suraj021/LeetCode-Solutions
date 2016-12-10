class Solution {
public:
    string convert(string s, int numRows) {
        vector<char> sol[numRows+1];
        int n= (int)s.length();
        int row= 1;
        int cycle= 0;
        
        if( numRows== 1 )
            return s;
        
        for( int i= 0; i< n; ++i ){
           
            sol[row].push_back( s[i] );
            
            if( row== numRows )
                cycle= 1;
            if( row== 1 )
                cycle= 0;
            
            if( cycle ){
                row--;
            }else{
                row++;
            }
            
        }
        
        string ans= "";
        
        for( int i= 1; i<= numRows; ++i ){
            for( int j= 0; j< sol[i].size(); ++j ){
                ans+= sol[i][j];
            }
        }
        
        return ans;
    }
};