class Solution {
public:
    void dfs(vector<int>&vis, int cur , vector<int>adj[]){
        vis[cur] =1 ;
        for(auto v : adj[cur]){
            if(!vis[v]){
                dfs(vis,v,adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>vis(n,0);
        int ans = 0;
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i= 0;  i <n ; i++){
            if(!vis[i]){ dfs(vis, i , adj); ++ans;}
        }
        return ans;
    }
};
