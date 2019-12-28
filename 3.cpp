class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()== 0) return 0;
        vector<int> lastSeen(256, -1); // last seen of a char
        int curr= 0; // start of the current unique substring
        int ans= 1; // initial ans
        lastSeen[s[0]]= 0; 
        
        // we look for the  window [curr, i]
        
        for(int i= 1; i< s.length(); ++i){
            if(lastSeen[s[i]] >= 0){  // if we have already seen the char
                curr= max(lastSeen[s[i]] + 1, curr);
            }
            lastSeen[s[i]] = i; // update the last seen
            ans= max(ans, i-curr+1);
        }
        
        return ans;
    }
};