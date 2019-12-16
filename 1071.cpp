class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m= str1.length();
        int n= str2.length();
        
        int l= 0;
        int i= 0;
        
        while( i < m && i < n ){
            if( str1[i] == str2[i] && n%(i+1) == 0 && m%(i+1) == 0)
                l= i+1;
            
            i++;
        }
        
        if(l== 0) return "";
        
        i= 0;
        
        while( i < m || i < n ){
            // cout << i << " " << i%l << endl;
            if( i < m && str1[i] != str1[i%l] ) return "";
            if( i < n && str2[i] != str2[i%l] ) return "";
            i++;
        }
        
        return str1.substr(0, l);
    }
};