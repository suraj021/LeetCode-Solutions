class Solution {
public:
    string reorganizeString(string S) {
        pair<int, char> freq[26];
        
        for(int i= 0; i< 26; ++i)
            freq[i]= { 0, 'a' + i };
        
        for(char c: S){
            freq[c-'a'].first++;
        }
        
        sort(freq, freq+26, [](pair<int, char> a, pair<int, char> b){
            return a.first > b.first;
        });
        
        if(2*freq[0].first - 1 > S.length()) return "";
        
        int j= 0;
        
        for(int i= 0; i< 26; ++i){
            if(freq[i].first == 0) break;
            while(freq[i].first){
                if(j>= S.length()) j= 1;
                S[j]= freq[i].second;
                j+= 2;
                freq[i].first--;
            }
        }
        
        return S;
    }
};