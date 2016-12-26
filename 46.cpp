class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n= (int)nums.size();
        vector< vector< int > > ans;
        
        if( n== 0 )
            return ans;
            
        permute( nums, 0, n-1, ans );
        
        return ans;
    }
    
    void permute( vector<int> &v, int l, int r, vector< vector<int> > &ans ){
        
        if( l== r ){
            ans.push_back( v );
            return ;
        }
        
        for( int i= l; i<= r; ++i ){
            std::swap( v[i], v[l] );
            permute( v, l+1, r, ans );
            std::swap( v[i], v[l] );
        }
    }
};