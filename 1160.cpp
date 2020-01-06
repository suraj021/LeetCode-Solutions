class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> ump;
        int ans= 0;
        
        for(char c: chars) ump[c]++;
        
        for(string word: words){
            unordered_map<char,int> f= ump;
            bool match= true;

            for(char c: word){
                f[c]--;
                if(f[c] < 0){
                    match= false;
                    break;
                }
            }
            
            if(match) ans+= word.length();
        }
        
        return ans;
    }
};