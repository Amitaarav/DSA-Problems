const int RED = -1;
const int WHITE = 0;
const int BLUE = 1;

class Solution {
public:
    bool dfs(int node, vector<vector<int>> & graph, vector<int> & color, int col){
        color[node] = col;

        for(auto nb : graph[node]){
            if(color[nb] == WHITE){
                bool ans = dfs(nb, graph, color, -1 * col);
                if(ans == false ) return false;
            }else if(color[nb] == color[node]){
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, WHITE);

        for(int i = 0; i < n; i++){
            if(color[i] == WHITE){
                bool ans = dfs(i, graph, color, RED);
                if(ans == false) return false;
            }
        }
        return true;
    }
};