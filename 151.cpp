class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        
        while(ss >> word){
            words.push_back(word);
        }
        
        word= "";
        
        for(int i= words.size()-1; i>= 0; --i){
            // reverse(words[i].begin(), words[i].end());
            word+= words[i] + " ";
        }
    
        if(word.length() > 1) word.pop_back();
        
        return word;
    }
};