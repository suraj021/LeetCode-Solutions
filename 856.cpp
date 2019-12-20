class Solution {
public:
    // https://leetcode.com/problems/score-of-parentheses/discuss/141975/c%2B%2B-solution-using-stack-(5ms)-detail-explained
    int scoreOfParentheses(string S) {
        stack<int> st;
        st.push(0);

        for(int i= 0; i< S.length(); ++i){
            if(S[i] == '('){
                st.push(0);
            } else {
                int temp = st.top();
                st.pop();
                int inner_par_val = temp > 0 ? 2*temp : 1; // 0 means no inner parentheses
                st.top()+= inner_par_val;
            }
        }
        
        return st.top();
    }
};