class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ans;
        vector<int> minFreq(26, INT_MAX);
        
        for(string s: A){
            vector<int> cnt(26, 0);
            for(char c: s)  cnt[c-'a']++;
            for(int i= 0; i< 26; ++i)   minFreq[i]= min(minFreq[i], cnt[i]);
        }
        
        for(int i= 0; i< 26; ++i){
            for(int j= 0; j< minFreq[i]; ++j)
                ans.push_back(string(1, i+'a'));
        }
        
        return ans;
    }
};