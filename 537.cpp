class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        pair<int, int> ca= parse(a);
        pair<int, int> cb= parse(b);
        
        string ans= to_string(ca.first*cb.first - ca.second*cb.second) + "+" + to_string(ca.first*cb.second + ca.second*cb.first) + "i";
        
        return ans;
    }
    
    pair<int, int> parse(string c){
        int p_index= find(c.begin(), c.end(), '+') - c.begin();
        int i_index= find(c.begin(), c.end(), 'i') - c.begin();
        
        int r= stoi(c.substr(0, p_index));
        int i= stoi(c.substr(p_index+1, i_index - p_index));
        
        return {r, i};
    }
};