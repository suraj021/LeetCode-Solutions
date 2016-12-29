class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if( board.size()!= 9 || board[0].size()!= 9 ){
            return false;
        }    
        
        bool r[9][9], c[9][9], block[3][3][9];
        
        memset( r, false, sizeof r );
        memset( c, false, sizeof c );
        memset( block, false, sizeof block );
        
        for( int i= 0; i< 9; ++i ){
            for( int j= 0; j< 9; ++j ){
                if( board[i][j]!= '.' ){
                    
                    int number= board[i][j] - '1';
                    
                    if( r[i][number] )
                        return false;
                    r[i][number]= true;
                    
                    if( c[j][number] )
                        return false;
                    c[j][number]= true;
                    
                    if( block[i/3][j/3][number] )
                        return false;
                    block[i/3][j/3][number]= true;
                    
                }
            }
        }
        
        return true;
    }
};