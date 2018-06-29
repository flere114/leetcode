class Solution {
public:
    int consecutiveNumbersSum(int N) {
        long long combination = 1;
        
        genPrimeTable();
        
        while (N % 2 == 0) {
            N /= 2;
        }
        for (const auto &p : prime) {
            int cnt = 0;
            
            while (N % p == 0) {
                N /= p;
                ++cnt;
            }
            
            if (cnt > 0) {
                combination *= (cnt + 1);
            }
        }
        
        if (N > 1) {
            combination *= 2;
        }
        
        return combination;
    }
private:
    vector <int> prime;
        
    void genPrimeTable() {
        prime.push_back(2);
        
        for (int i = 3; i < 100005; ++i) {
            bool ok = true;
            for (const auto &p : prime) {
                if (i % p == 0) {
                    ok = false;
                    break;
                }
                if (static_cast<long long>(p) * p >= i) {
                    break;
                }
            }
            if (ok) {
                prime.push_back(i);
            }
        }
    }
};
