class Solution {
public:
    int countSubstrings(string s) {
        int ans= 0;
        int n= (int)s.length();
        
        for(int i= 0; i< n; ++i){
            // think of i as the middle of the palindrome.
            // the length of the palindrome can be odd or even
            
            // in case of odd length palindrome;
            for(int l= i, r= i; l >= 0 && r < n && s[l] == s[r]; --l, ++r) ans++;
            
            // in case of even length palidrome
            for(int l= i, r= i+1; l >= 0 && r < n && s[l] == s[r]; --l, ++r) ans++;
        }
        
        return ans;
    }
};