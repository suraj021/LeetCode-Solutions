class Solution {
public:
    bool validPalindrome(string s) {
        return _validPalindrome(s, 0, s.length()-1, 1);
    }
    
    bool _validPalindrome(string& s, int l, int r, int c){
        if(s== "" || l > r) return true;
        if(s[l] == s[r])
            return _validPalindrome(s, l+1, r-1, c);
        else
            return c ? _validPalindrome(s, l, r-1, c-1) || _validPalindrome(s, l+1, r, c-1) : false;
    }
};