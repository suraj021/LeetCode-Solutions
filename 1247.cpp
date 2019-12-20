class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if(s1 == s2) return 0;
        if(s1.length() != s2.length())  return -1;
        map<char, int> mp;
        
        for(int i= 0; i< s1.length(); ++i){
            if(s1[i] == 'x' && s1[i] != s2[i]){
                mp['x']++;
            }
            if(s1[i] == 'y' && s1[i] != s2[i]){
                mp['y']++;
            }
        }
        
        if((mp['x']+mp['y'])%2) return -1;
        
        return (mp['x']/2 + mp['x']%2) + (mp['y']/2 + mp['y']%2);
    }
};