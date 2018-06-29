/*
 * state space search that using BFS.
 * state : dis[current node][visited node represent by bit mask]
 */
class Solution {
public:
    int shortestPathLength(vector<vector<int>> &graph) {
        int ans = 1000;
        for (int i=0; i<graph.size(); ++i) {
            ans = min(ans, bfs(graph, i));
        }
        
        return ans;
    }
private:
    int bfs(const vector<vector<int>> &graph, int st) {
        const int N = graph.size();
        int target = (1<<N) - 1;
        vector <vector<int>> dis(N, vector<int>(1<<N, INF));
        vector <vector<bool>> inQ(N, vector<bool>(1<<N, false));
        queue <pair<int,int>> q;
        
        q.push(make_pair(st, 1<<st));
        dis[st][1<<st] = 0;
        inQ[st][1<<st] = true;
        
        while (!q.empty()) {
            int now = q.front().first;
            int state = q.front().second;
            q.pop();
            inQ[now][state] = false;
            
            if (state == target) {
                return dis[now][state];
            }
            
            for (int i=0; i<graph[now].size(); ++i) {
                int next = graph[now][i];
                int next_state = state | (1<<next);
                
                if (dis[now][state] + 1 < dis[next][next_state]) {
                    dis[next][next_state] = dis[now][state] + 1;
                    
                    if (!inQ[next][next_state]) {
                        inQ[next][next_state] = true;
                        q.push(make_pair(next, next_state));
                    }
                }
            }
        }
        
        return INF;
    }
private:
    const int INF = 1000;
};
