class Solution {
public:
    
    class Trie {
        public: 
        Trie *subs[26];
        vector<string> suggestions;
        
        Trie(){
            for(int i= 0; i< 26; ++i)
                subs[i]= NULL;
        }
    };

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        Trie *root= new Trie();
        
        sort(products.begin(), products.end());
        
        for(string word: products){
            Trie *t= root;
            for(char c: word){
                int key= c-'a';
                if(t->subs[key] == NULL)
                    t->subs[key] = new Trie();
                    t= t->subs[key];
                    if(t->suggestions.size() < 3)
                        t->suggestions.push_back(word);
            }
        }
        
        
        Trie* t= root;
        for(char c: searchWord){
            if(t) t= t->subs[c-'a'];
            ans.push_back(!t ? vector<string>() : t->suggestions);
        }
        
        return ans;
    }
};