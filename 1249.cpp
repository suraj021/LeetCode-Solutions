class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s== "") return "";
        
        vector<bool> index(s.length(), true);
        stack<int> st;
        
        for(int i= 0; i< s.length(); ++i){
            if(s[i]== '(')  st.push(i);
            if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                } else{
                  index[i]= false;
                }
            }
        }
        
        while(!st.empty()){
            index[st.top()]= false;
            st.pop();
        }
        
        string ans= "";
        
        for(int i= 0; i< s.length(); ++i){
            if(index[i]) ans+= s[i];
        }
    
        return ans;
    }
};