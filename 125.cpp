class Solution {
public:
    bool isPalindrome(string s) {
        if(s == "") return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        int i= 0, j= s.length()-1;
        
        while(i < j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            
            if(s[i] != s[j])    return false;
            
            i++; j--;
        }
        
        return true;
    }
};