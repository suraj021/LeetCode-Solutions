class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n= (int)s.length();
        int m= (int)t.length();
        
        int i= 0, j= 0;
        
        while(i < m && j < n){
            if(s[j]== t[i]) j++;
            i++;
        }   
        
        return j==n;
    }
};