class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n= (int)nums.size();
        vector< int > ans( 2, -1 );
        
        if( n== 0 ){
            return ans;
        }else if( n== 1 && nums[0]== target ){
            ans[0]= ans[1]= 0;
            return ans;
        }else if( n== 1 && nums[0]!= target ){
            ans[0]= ans[1]= -1;
            return ans;
        }
        
        int f= first( nums, 0, n-1, target );
        
        if( f== -1 ){
            ans[0]= ans[1]= -1;
            return ans;
        }
        
        int l= last( nums, f, n-1, target );
        
        ans[0]= f;
        ans[1]= l;
        
        return ans;
    }
    
    int first( vector<int> a, int l, int r, int t ){
        while( l <= r ){
            int m= l + (r-l)/2;
            if( a[m] < t ){
                l= m+1;
            }else if( a[m] > t ){
                r= m-1;
            }else{
                if( m== 0 ){
                    return 0;
                }else if( a[m-1] < t ){
                    return m;
                }else{
                    r= m-1;
                }
            }
        }
        
        return -1;
    }
    
    int last( vector<int> a, int l, int r, int t ){
        int n= (int)a.size();
        
        while( l <= r ){
            int m= l + (r-l)/2;
            if( a[m] < t ){
                l= m+1;
            }else if( a[m] > t ){
                r= m-1;
            }else{
                if( m== n-1 ){
                    return m;
                }else if( a[m+1] > t ){
                    return m;
                }else{
                    l= m+1;
                }
            }
        }
        
        return -1;
    }
    
    
    
};