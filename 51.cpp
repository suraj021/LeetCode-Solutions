#define ff first
#define ss second

typedef pair<int, int> pii;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        vector< vector<string> > ans;
        vector< string > vs( n, string( n, '.' ) );
        vector<pii> pos;
    
        solution( ans, vs, 0, n, pos );
    
        return ans;
    }
    
private:
    bool safe( vector<pii> pos, int i, int j ){
        int n= (int)pos.size();
    
        //cout << '\t' << '\t' << i << ' ' << j << endl;
    
        for( int k= 0; k< n; ++k ){
            int x= pos[k].ff;
            int y= pos[k].ss;
    
            if( x== i || y== j )
                return false;
            if( abs(x-i)== abs(y-j) || (x+y)==(i+j) )
                return false;
        }
    
        return true;
    }
    
    void solution( vector< vector<string> > &ans, vector<string> &vs, int row, int n, vector<pii> &pos ){
    
        /*cout << row+1 << endl;
        for( int i= 0; i< pos.size(); ++i ){
            cout << '\t' << pos[i].ff << ' ' << pos[i].ss << endl;
        }*/
    
        if( row== n ){
            ans.push_back( vs );
            return ;
        }
    
        for( int col= 0; col < n; ++col ){
            if( safe( pos, row, col ) ){
    
                pos.push_back( { row, col } );
                vs[row][col]= 'Q';
    
                solution( ans, vs, row+1, n, pos );
    
                pos.pop_back();
                vs[row][col]= '.';
            }
        }
    
    }
    
};