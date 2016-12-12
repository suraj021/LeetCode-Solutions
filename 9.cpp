class Solution {
public:
    bool isPalindrome(int x) {
        int y= reverse( x );
        
        if( x < 0 )
            return false;
        return ( x== y );
    }
    
    int reverse( int x ){
        int num= 0;
        
        while( x ){
            int r= x%10;
            num= num*10 + r;
            x/= 10;
        }
        
        return num;
    }
};