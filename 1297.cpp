class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        cout << s.length() << endl;
        map<char, int> mp;
        map<string, int> freq;
        int n= s.length();
        int ans= 0;
        
        if(s == "") return 0;
        
        for(int i= 0; i<= n-minSize; ++i){
            int j= i;
            while(j < n && j <= i+minSize && mp.size() <= maxLetters){
                mp[s[j]]++;

                if(mp.size() > maxLetters) break;
                
                if(j-i+1 >= minSize){
                    string subst= s.substr(i, j-i+1); 
                    freq[subst]++;
                    ans= max(ans, freq[subst]);
                }
                j++;
            }
            
            mp.clear();
        }
        return ans;
    }
};