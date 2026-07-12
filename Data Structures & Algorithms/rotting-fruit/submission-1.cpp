class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int ones= 0 ;
        for(int i = 0 ;i < grid.size() ; i++){
            for(int j=0; j< grid[0].size(); j++){
                if(grid[i][j] == 2) q.push({i,{j,0}});
                else if(grid[i][j] == 1) ++ones;
            }
        }
        int rows[] = {0,0,1,-1} , cols[]= {1,-1,0,0} , ans = 0 , mark = 0;
        while(!q.empty()){
            int qsize = q.size();
            cout<<qsize<<endl;
            for(int t = 0 ; t < qsize ; t++){
                pair<int,pair<int,int>>cur = q.front(); q.pop();
                int dx = cur.first, dy =cur.second.first , dis = cur.second.second;
                for(int i=0;i<4;i++){
                    int nr = dx + rows[i] , nc = dy + cols[i];
                    if(nr>=0 and nr<grid.size() and nc>=0 and nc< grid[0].size() and grid[nr][nc] == 1){
                        grid[nr][nc] = 0;
                        q.push({nr,{nc,dis+1}});
                        ans = max(ans, dis+1); 
                        ++mark;
                    }
                }
            }
        }
        return ones == mark ?ans :-1;
    }
};
// 2,1,1
// 0,1,1
// 1,0,1





