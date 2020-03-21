typedef pair<int,int> pii;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int rows= g.size();
        int cols= g[0].size();
        int empty= 0;
        int dir[4][2]= {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int steps= 0;
        int fresh= 0;

        queue<pii> q;
        
        for(int i= 0; i< rows; ++i){
            for(int j= 0; j< cols; ++j){
                empty+= g[i][j] == 0 ? 1 : 0;
                fresh+= g[i][j] == 1 ? 1 : 0;
                if(g[i][j]== 2){
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty()){
            int sz= q.size();
            int isFresh= false;
            
            for(int i= 0; i< sz; ++i){
                int x= q.front().first;
                int y= q.front().second;
                q.pop();
                
                for(int d= 0; d< 4; ++d){
                    int xdx= x + dir[d][0];
                    int ydy= y + dir[d][1];
                    
                    if(xdx >= 0 && xdx < rows && ydy >=0 && ydy < cols){
                        if(g[xdx][ydy]== 1){
                            fresh--;
                            g[xdx][ydy]= 2;
                            q.push({xdx, ydy});
                            isFresh= true;
                        }
                    }
                }
            }
            
            steps+= isFresh ? 1 : 0;
        }
        
        if(fresh) return -1;
        
        return steps;
    }
};