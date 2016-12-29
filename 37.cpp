class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        solution( board, 9 );
    }
    
    bool solution( vector< vector<char> > &board, int n ){
    
        for( int row= 0; row < n; ++row ){
            for( int col= 0; col < n; ++col ){
                if( board[row][col]== '.' ){
                    for( char c= '1'; c<= '9'; ++c ){
                        
                        if( safe( board, row, col, c ) ){
                            
                            board[row][col]= c;
                            if( solution( board, n ) ){
                                return true;
                            }else
                            board[row][col]= '.';
                        }
                        
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool safe( vector< vector<char> > board, int row, int col, char c ){
        
        for( int i= 0; i< 9; ++i ){
            if( board[row][i]!= '.' && board[row][i]== c )
                return false;
            if( board[i][col]!= '.' && board[i][col]== c )
                return false;
            if(board[3*(row/3) + i/3][ 3*(col/3) + i%3] != '.' && board[3*(row/3) + i/3][3*(col/3) + i%3] == c) 
                return false;
        }
        
        return true;
    }
};