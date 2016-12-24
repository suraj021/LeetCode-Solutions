class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n= (int)a.size();
        
        a.resize( n+1 );
        a[n]= -1;
        
        for( int i= 0; i< n; ++i ){
            while( a[i] >= 0 && a[i] <= n && a[a[i]] != a[i] )
                swap( a[i],a[a[i]] );
        }
        
        for( int i= 0; i< n; ++i )
            cout << a[i] << ' ';
        
        for( int i= 0; i< n; ++i )
            if( a[i] != i )
                return i;
        return n;
    }
};