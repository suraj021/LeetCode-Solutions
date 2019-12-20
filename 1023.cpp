class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        
        for(string query: queries){
            ans.push_back(isMatch(query, pattern));
        }
        
        return ans;
    }
    
    bool isMatch(string query, string pattern){
        int i= 0;
        for(char c: query){
            if(i < pattern.length() && c == pattern[i]) i++;
            else if(c < 'a') return false;
        }
        
        return i == pattern.length();
    }
};