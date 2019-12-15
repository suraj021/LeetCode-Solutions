class Solution {
public:
    bool isValid(string s) {
        
        if(s.length()%2)
            return false;
        
        stack<char> st;
                
        for(char c: s){
            cout << c << " " << st.size() << endl;
            if(c == '(')
                st.push(')');
            else if(c == '{')
                st.push('}');
            else if(c == '[')
                st.push(']');
            else if(st.empty() || c != st.top())
                return false;
            else
                st.pop();
        }
        
        return st.empty();
    }
};