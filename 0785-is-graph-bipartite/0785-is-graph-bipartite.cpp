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

    bool bfs(int node, vector<vector<int>> & graph, vector<int> & colors){
        queue<int> q;
        q.push(node);

        colors[node] = RED;

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int col = colors[curr];

            for(int nb : graph[curr]){
                if(colors[nb] == WHITE){
                    q.push(nb);
                    colors[nb] = -1 * col;
                }else if(colors[nb] == colors[curr]){
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, WHITE);

        for(int i = 0; i < n; i++){
            if(color[i] == WHITE){
                bool ans = bfs(i, graph, color);
                if(ans == false) return false;
            }
        }
        return true;
    }
};