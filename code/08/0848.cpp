class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int shift = 0;
        for (int i=S.length()-1; i>=0; --i) {
            shift += shifts[i];
            shift %= MOD;
            
            int ch = (S[i] - 'a' + shift) % MOD;
            S[i] = 'a' + ch;
        }
        
        return S;
    }
private:
    const int MOD = 26;
};
