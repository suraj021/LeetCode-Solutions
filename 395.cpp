class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans= 0;
        
        for(int i= 1; i<= 26; ++i){
            ans= max(ans, longestSubstringWithTargetUniqueLetters(s, k, i));
        }
        
        return ans;
    }
    
    int longestSubstringWithTargetUniqueLetters(string &s, int k, int uniqueTargets){
        int mp[26]= {0};
        int left, right;
        int numUnique= 0;   // number of unique characters in [left, right]
        int numUniqueAtleastK= 0; // number of char in [left, right] with frequency >= k
        int ans= 0;
        
        left= right= 0;
        
        while(right < s.length()){
            int rc= s[right] - 'a';
            
            if(mp[rc] == 0) numUnique++; // if the char is encountered for first time
            mp[rc]++;
            
            if(mp[rc] == k) numUniqueAtleastK++; // if freqency of the char equals k
            
            while(numUnique > uniqueTargets){ // while number of unique chars in the range is greater than required targets
                int lc= s[left] - 'a';
                
                if(mp[lc] == k) numUniqueAtleastK--;
                mp[lc]--;
                if(mp[lc] == 0) numUnique--;
                
                left++;
            }
            
            if(numUnique == uniqueTargets && numUniqueAtleastK == uniqueTargets){
                ans= max(ans, right-left+1);
            }
            
            right++;
        }
        
        return ans;
    }
};