class Solution {
public:
    
    static bool sortPairs(vector<int>& a, vector<int>& b){
        if(a[0] < b[0]) return true;
        if(a[0] > b[0]) return false;
        return a[1] < b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n= pairs.size();
        if( n== 0 ) return 0;
        int lis[n];
        int ans= -1;
        
        sort(pairs.begin(), pairs.end(), sortPairs);
        
        for( int i= 0; i< n; ++i ){
            lis[i]= 1;
            for( int j= 0; j< i; ++j ){
                if(pairs[j][1] < pairs[i][0] ){
                    lis[i]= max( lis[i], lis[j] + 1);
                }
            }
            ans= max( ans, lis[i] );
        }
        
        return ans;
    }
};