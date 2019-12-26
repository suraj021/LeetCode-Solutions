class Solution {
public:
    int calculate(string s) {
        return calculateUsingStack(s);
    }
    
    int calculateUsingStack(string s){
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        // cout << s << " " << s.length() << endl;
        stack<long> st;
        char sign= '+';
        int len= s.length();
        long res= 0;
        
        for(int i= 0; i< len; ){
            if(s[i] == ' '){ 
                i++ ;
                continue;
            }
            long currVal= 0;
            
            // cout << "prev i: " << i << " " << "prev sign: " << sign << ", " ;
            
            while(i < len && isdigit(s[i])){
                currVal= currVal * 10 + s[i] - '0';
                i++;
            }
            
            // cout << i << " " << currVal << ", ";
            
            if(sign== '+'){
                st.push(currVal);
            } else if(sign == '-'){
                st.push(-currVal);
            } else if(sign == '*'){
                long n= st.top();
                st.pop();
                st.push(n*currVal);
            } else if(sign == '/'){
                long n= st.top();
                st.pop();
                st.push(n/currVal);
            }
            
            
            if(i < len){
                sign= s[i];
                i++;
            }
            
            // cout << "new i: " << i << " new sign : " << sign <<  endl;
        }
        
        while(!st.empty()){
            // cout << st.top() << " ";
            res+= st.top();
            st.pop();
        }
        
        return res;
    }
};