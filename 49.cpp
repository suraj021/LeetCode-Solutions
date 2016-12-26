class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        int n= (int)str.size();
        vector< vector<string> > ans;
        unordered_map< string, vector<string> > mp;
        
        if( n== 0 )
            return ans;
        
        for( int i= 0; i< n; ++i ){
            string s= str[i];
            sort( s.begin(), s.end() );
            mp[s].push_back( str[i] );
        }
        
        for( auto &it: mp ){
            vector< string > vs= it.second;
            ans.push_back( vs );
        }
        
        return ans;
    }
};