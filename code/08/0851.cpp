class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        N = quiet.size();
        g.resize(N);
        visit.resize(N);
        
        for (const auto &r : richer) {
            g[r[1]].push_back(r[0]);
        }
        
        vector <int> ans(N);
        
        for (int i=0; i<quiet.size(); ++i) {
            int qVal = N;
            visit.assign(N, false);
            findAns(i, quiet, ans[i], qVal);
        }
        
        return ans;
    }
private:
    void findAns(int node, const vector<int> &quiet, int &ans, int &qVal) {
        if (visit[node]) {
            return;
        }
        visit[node] = true;
        
        if (quiet[node] < qVal) {
            qVal = quiet[node];
            ans = node;
        }
        for (int i=0; i<g[node].size(); ++i) {
            findAns(g[node][i], quiet, ans, qVal);
        }
    }
private:
    int N;
    vector<bool> visit;
    vector<vector<int>> g;
};
