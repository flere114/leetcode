class Solution {
public:
    int largestIsland(vector<vector<int>> &grid) {
        int ans = 0, id = 2;
        
        for (int x = 0; x < grid.size(); ++x) {
            for (int y = 0; y < grid.size(); ++y) {
                if (grid[x][y] == 1) {
                    int size = bfs(x, y, id, grid);
                    ans = max(ans, size);
                    idSizeMap[id] = size;
                    ++id;
                }
            }
        }
        
        for (int x = 0; x < grid.size(); ++x) {
            for (int y = 0; y < grid.size(); ++y) {
                if (grid[x][y] == 0) {
                    ans = max(ans, concate(x, y, grid));
                }
            }
        }
        
        return ans;
    }
private:
    const int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    map <int,int> idSizeMap;
    
    bool isInGrid(int x, int y, vector<vector<int>> &grid) {
        return (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size());
    }
    int concate(int x, int y, vector<vector<int>> &grid) {
        int size = 1;
        set <int> idSet;
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            
            if (isInGrid(nx, ny, grid) && idSet.end() == idSet.find(grid[nx][ny])) {
                idSet.insert(grid[nx][ny]);
                size += idSizeMap[grid[nx][ny]];
            }
        }
        
        return size;
    }
    int bfs(int x, int y, int id, vector<vector<int>> &grid) {
        int size = 0;
        queue <pair<int,int>> q;
        map <pair<int,int>, bool> xyInMap;
        
        q.push(make_pair(x, y));
        xyInMap[make_pair(x, y)] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            ++size;
            grid[x][y] = id;
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (isInGrid(nx, ny, grid) && xyInMap.end() == xyInMap.find(make_pair(nx, ny)) && grid[nx][ny] == 1) {
                    q.push(make_pair(nx, ny));
                    xyInMap[make_pair(nx, ny)] = true;
                }
            }
        }
        
        return size;
    }
};
