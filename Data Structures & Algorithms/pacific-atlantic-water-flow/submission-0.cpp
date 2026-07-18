class Solution {
public:
    void trav(vector<vector<int>>& heights, int p, int q, vector<vector<int>>&mat){
        int rows[]= {1,-1, 0,0}, cols[] ={0,0,1,-1};
        for(int i= 0; i< 4;i++){
            int nr = p + rows[i] , nc = q  + cols[i];
            // cout<<p<<" "<<q<<" "<<nr<<" "<<nc<<endl; 
            if(nr >=0 and nr < heights.size() and nc >=0 and nc < heights[0].size() and heights[p][q] <= heights[nr][nc]
            and mat[nr][nc] == 0 ){
                mat[nr][nc]=1;
                trav(heights,nr,nc,mat);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& height) {
        int n = height.size() , m = height[0].size();
        vector<vector<int>>ans;
        vector<vector<int>>at(n,vector<int>(m,0));
        vector<vector<int>>pac(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            pac[i][0] =1;
            trav(height,i,0,pac);
            at[i][m-1]=1;
            trav(height, i,m-1,at);
        }
         for(int i=0;i<m;i++){
            pac[0][i] =1;
            trav(height,0,i,pac);
            at[n-1][i]=1;
            trav(height,n-1,i, at );
        }
        for(int i= 0 ;i <n;i++){
            for(int j =  0 ; j< m ; j++){
                cout<<pac[i][j]<<" ";
                if(at[i][j] == 1 and pac[i][j] == 1){
                    vector<int>temp= { i,j};
                    ans.push_back(temp);
                }
            }
            cout<<endl;
        }
        for(int i= 0 ;i <n;i++){
            for(int j =  0 ; j< m ; j++){
                cout<<(at[i][j])<<" ";
                // if(at[i][j] == 1 and pac[i][j] == 1){
                //     vector<int>temp= { i,j};
                //     ans.push_back(temp);
                // }
            }
            cout<<endl;
        }
        return ans;
    }
};
// pac
// 1 1 1 1 1
// 1 1 1 1 0
// 1 1 1 1 0

// at
// 0 0 0 1 1
// 0 0 0 1 1
// 1 1 1 1 1


// 00 <-> 0,m-1
// n-1,0 <-> n-1,m-1