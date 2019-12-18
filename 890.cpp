class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string pt= F(pattern);
                
        for(int i= 0; i< words.size(); ++i){
            if(F(words[i]) == pt) ans.push_back(words[i]);
        }
        return ans;
    }
    
    string F(string w) {
        unordered_map<char, int> m;
        for (char c : w) if (!m.count(c)) m[c] = m.size();
        for (int i = 0; i < w.length(); ++i) w[i] = 'a' + m[w[i]];
        return w;
    }
};