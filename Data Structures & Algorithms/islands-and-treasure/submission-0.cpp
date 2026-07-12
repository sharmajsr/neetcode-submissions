class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        stack<pair<int,pair<int,int>>>st;
        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0; j< grid[0].size() ; j++) {
                if(grid[i][j] == 0){
                    st.push({i,{j,0}});
                }
            }
        }
        int rows[] = {0,0,1,-1} , cols[] = {1,-1,0,0} ;
        while(!st.empty()){
            pair<int,pair<int,int>> cur = st.top(); st.pop();
            int dx = cur.first , dy = cur.second.first , dis = cur.second.second;
            for(int i = 0 ; i<  4 ; i++){
                int nr = dx + rows[i], nc = dy + cols[i] ;
                if( nr>=0 and nr < grid.size() and nc >= 0 and nc < grid[0].size() and grid[nr][nc] !=-1 and grid[nr][nc] > dis+1){
                    grid[nr][nc] = min(grid[nr][nc] , dis+1);
                    st.push({nr,{nc,dis+1}});
                }
            }
        }
        
    }
};
