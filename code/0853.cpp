class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector <pair<int,int>> comb;
        
        for (int i=0; i<position.size(); ++i) {
            comb.emplace_back(position[i], speed[i]);
        }
        sort(comb.begin(), comb.end());
        
        int ans = 0;
        int last = comb.size()-1;
        while (last >= 0) {
            ++ans;
            long long left = target - comb[last].first;
            long long spd = comb[last].second;
            // so the time for the last one to reach target would be (left / spd)
            
            // then we need to find the others that can reach target within time (left / spd)
            --last;
            while (last >= 0) {
                long tmpLeft = target - comb[last].first;
                long tmpSpd = comb[last].second;
                
                // we need to check if (tmpLeft / tmpSpd) <= (left / spd)
                // it means (tmpLeft * spd) <= (left * tmpSpd)
                if (tmpLeft * spd <= left * tmpSpd) {
                    --last;
                    continue;
                } else {
                    break;
                }
            }
        }
        
        return ans;
    }
};
