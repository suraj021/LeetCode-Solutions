class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr, pre, ans;
        curr= 1; pre= 0; ans= 0;
        
        for(int i= 1; i< s.length(); ++i){
            if(s[i] == s[i-1]){
                curr++;
            } else {
                ans+= min(curr, pre);
                pre= curr;
                curr= 1;
            }
        }
        
        return ans + min(curr, pre);
    }
};