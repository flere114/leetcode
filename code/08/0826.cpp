class Solution {
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
        vector <pair<int,int>> d_p;
        vector <int> maxProfit(difficulty.size());
        
        for (int i = 0; i < difficulty.size(); ++i) {
            d_p.emplace_back(difficulty[i], profit[i]);
        }
        sort(d_p.begin(), d_p.end());
        for (int i = 0; i < d_p.size(); ++i) {
            difficulty[i] = d_p[i].first;
            profit[i] = d_p[i].second;
            
            if (i == 0) {
                maxProfit[i] = profit[i];
            } else {
                maxProfit[i] = max(maxProfit[i-1], profit[i]);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < worker.size(); ++i) {
            int idx = upper_bound(difficulty.begin(), difficulty.end(), worker[i]) - difficulty.begin() - 1;
            
            if (idx >= 0) {
                ans += maxProfit[idx];
            }
        }
        
        return ans;
    }
};
