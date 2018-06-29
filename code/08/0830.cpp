class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        vector<int> cur = {0, 0};
        
        for (int i = 1; i < S.length(); ++i) {
            if (S[i] == S[cur[0]]) {
                cur[1] = i;
            } else {
                if (cur[1] - cur[0] >= 2) {
                    ans.push_back(cur);
                }
                cur[0] = cur[1] = i;
            }
        }
        if (cur[1] - cur[0] >= 2) {
            ans.push_back(cur);
        }
        
        return ans;
    }
};
