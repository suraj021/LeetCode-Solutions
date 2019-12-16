class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m= (int)name.length();
        int n= (int)typed.length();
        
        if(m > n)   return false;
        
        int i, j;    
        i= j= 0;
        
        while(i < m && j < n){
            int a, b;
            a= b= 0;
            
            if(name[i] != typed[j]) return false;
            
            while(i < m-1 && name[i] == name[i+1]){
                i++;
                a++;
            }
            
            while(j< n-1 && typed[j] == typed[j+1]){
                j++;
                b++;
            }
            
            if( a > b ) return false;
            
            i++; j++;
        }
        
        if(i < m || j < n) return false;
        
        return true;
    }
};