class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool found= false;
        int m= board.size();
        int n= board[0].size();
        
        for(int i= 0; i< m; ++i){
            for(int j= 0; j< n; ++j){
                if(dfs(i, j, m, n, 0, word, board))
                    return true;
            }
        }
        
        return false;
    }
    
    bool dfs(int i, int j, int m, int n, int k, string &word, vector<vector<char>> &board){
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k])
            return false;
        if(k == word.length()-1)
            return true;
        
        board[i][j]= '#';
        
        bool found= dfs(i+1, j, m, n, k+1, word, board) || dfs(i-1, j, m, n, k+1, word, board) || dfs(i, j-1, m, n, k+1, word, board) || dfs(i, j+1, m, n, k+1, word, board);
        
        board[i][j]= word[k];
        
        return found;
    }
};