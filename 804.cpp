class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morseCode[]= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> us;
        
        for(int i= 0; i< words.size(); ++i){
            string morse= "";
            for(int j= 0; j< words[i].length(); ++j){
                morse+= morseCode[words[i][j] - 'a'];
            }
            
            us.insert(morse);
        }
        
        return us.size();
    }
};