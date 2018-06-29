class Solution {
public:
    int uniqueLetterString(string S) {
        int ans = 0;
        
        for (int i = 0; i < 26; ++i) {
            ans += cal(S, 'A' + i);
            ans %= MOD;
        }
        
        return ans;
    }
private:
    const int MOD = 1000000007;
    
    int cal_sub(int preIdx, int curIdx, int postIdx) {
        return (curIdx - preIdx + 1) * (postIdx - curIdx + 1);
    }
    int cal(const string &s, char ch) {
        vector <int> pos;
        int ans = 0;
        
        pos.push_back(-1);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ch) {
                pos.push_back(i);
            }
        }
        pos.push_back(s.length());
        
        for (int i = 1; i < pos.size() - 1; ++i) {
            ans += cal_sub(pos[i-1] + 1, pos[i], pos[i+1] - 1);
            ans %= MOD;
        }
        
        return ans;
    }
};
