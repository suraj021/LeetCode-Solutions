class Solution {
public:
    string countAndSay(int n) {
        char c[]= { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        string s= "1";
        
        while( --n ){
            string t= "";
            int l= (int)s.length();
            
            for( int i= 0; i< l;  ){
                int j= i+1;
                while( j < l && s[j]== s[i] )
                    j++;
                
                j--;
                
                //cout << c[j-i] << s[i];
                
                t= t + c[j-i] + s[i];
                i= j+1;
            }
            
            s= t;
            cout << s << ' ' ;
        }
        
        return s;
    }
};