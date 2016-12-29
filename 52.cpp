#define ff first
#define ss second
typedef pair<int,int> pii;

class Solution {
public:
    int totalNQueens(int n) {
        int count= 0;
        vector<pii> pos;
        
        solution( 0, n, pos, count );
        
        return count;
    }
    
    void solution( int row, int n, vector<pii> pos, int &cnt ){
        if( row== n ){
            cnt++;
            return ;
        }
        
        for( int col= 0; col < n; ++col ){
            if( safe( row, col, pos ) ){
                pos.push_back( { row, col } );
                solution( row+1, n, pos, cnt );
                pos.pop_back();
            }
        }
    }
    
    bool safe( int row, int col, vector<pii> &pos ){
        for( int i= 0; i< (int)pos.size(); ++i ){
            int x= pos[i].ff;
            int y= pos[i].ss;
            
            if( x== row || y== col )
                return false;
            
            if( abs(x-row)== abs(y-col) )
                return false;
            
            if( x+y == row+col )
                return false;
        }
        
        return true;
    }
    
    
};