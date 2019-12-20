class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        
        for(int i= 0; i< s.length(); ++i){
            if(s[i]== ' ') continue;

            int j= i;
            while(s[j] != ' ' && j < s.length()){
                st.push(s[j]);
                j++;
            }
            
            while(!st.empty()){
                s[i]= st.top();
                i++;
                st.pop();
            }
        }
        
        return s;
    }
};