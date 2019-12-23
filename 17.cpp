class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> mp;
        
        mp['2']= "abc";
        mp['3']= "def";
        mp['4']= "ghi";
        mp['5']= "jkl";
        mp['6']= "mno";
        mp['7']= "pqrs";
        mp['8']= "tuv";
        mp['9']= "wxyz";
        
        vector<string> ans;
        
        if(digits.length() == 0) return ans;
        
        _letterCombinations(digits, "", 0, mp, ans);
        
        return ans;
    }
    
    void _letterCombinations(string &digits, string s, int index, map<char, string>& mp, vector<string> &ans){
        if(index >= digits.length()){
            ans.push_back(s);
            return;
        }
        
        for(char c: mp[digits[index]]){
            _letterCombinations(digits, s + c, index+1, mp, ans);
        }
    }
};