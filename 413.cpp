class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int ans= 0;
        int n= (int)a.size();
        for( int i= 0; i< n; ++i ){
            int j= i;
            if( j+1 < n ){
                int d= a[j+1] - a[j];
                while( j+1 < n && a[j+1]-a[j] == d ) j++;
                if( j > i+1 ) {
                    int x= j-i+1;
                    ans+= (x-1)*(x-2)/2;
                }
                i= j-1;
            } else {
                i++;
            }
        }
        
        return ans;
    }
};