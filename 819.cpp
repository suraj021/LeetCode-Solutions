class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> allwords;
        string word;
        
        map<string, bool> bannedwords;
        
        for (auto &c: paragraph) c = isalpha(c) ? tolower(c) : ' ';
        
        stringstream ss(paragraph);
        
        cout << paragraph << endl;
        
        for(int i= 0; i< banned.size(); ++i){
            transform(banned[i].begin(), banned[i].end(), banned[i].begin(), ::tolower);
            bannedwords[banned[i]]= true;
        }
        
        while(ss >> word){
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if(!isalnum(word[word.length()-1])){
                word.pop_back();
            }
            
            if(!bannedwords[word]){
                allwords.push_back(word);
            }
        }
        
        string ans;
        map<string, int> freq;
        int maxfreq= -1;

        for(int i= 0; i< allwords.size(); ++i){
            if(!bannedwords[allwords[i]]){
                freq[allwords[i]]++;
                
                if(freq[allwords[i]] > maxfreq){
                    ans= allwords[i];
                    maxfreq= freq[allwords[i]];
                }
            }
        }
        
        return ans;
    }
};