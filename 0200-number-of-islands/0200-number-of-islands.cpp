const char LAND = '1';
const char WATER = '0';

const int dx[4] = {-1, 1, 0, 0 };
const int dy[4] = {0, 0, -1, 1 };

class Solution {
public:
    bool valid(int x, int y, vector<vector<char>> &grid){
        return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size());
    }

    void islandsDFS(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited ){
        visited[x][y] = true;

        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(valid(newX, newY, grid) && !visited[newX][newY] && grid[newX][newY] == LAND){
                islandsDFS(newX, newY, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();


        vector<vector<bool>> visited(n, vector<bool> (m, false));

        int numsOfIslands = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == LAND && !visited[i][j]){
                    islandsDFS(i, j, grid, visited);
                    numsOfIslands++;
                }
            }
        }

        return numsOfIslands;
    }
};