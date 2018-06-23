/*
 * First try, I used greedy without proof and I think maybe.... it's wrong.
 * And yes, it's totally wrong :)
 * 
 * Then I try a brute force search by BFS and get accepted.
 * For each string, we will only generate a new string that is more similar with target.
 * The amount of the choice is small, so the time complexity would be ok.
 */

class Solution {
public:
    int kSimilarity(string A, string B) {
        queue <pair<string, int>> q;
        set <string> s;
        
        s.insert(A);
        q.push(make_pair(A, 0));
        
        while (!q.empty()) {
            string tmpA = q.front().first;
            int step = q.front().second;
            q.pop();
            
            int pos = findFirstUnmatch(tmpA, B);
            if (pos == A.length()) {
                return step;
            }
            
            // every turn, always make pos match
            for (int i = pos+1; i < A.length(); ++i) {
                if (tmpA[i] == B[pos]) {
                    string nextA = tmpA;
                    swap(nextA[i], nextA[pos]);
                    
                    if (s.find(nextA) == s.end()) {
                        s.insert(nextA);
                        q.push(make_pair(nextA, step+1));
                    }
                }
            }
        }
    }
private:
    int findFirstUnmatch(const string &A, const string &B) {
        for (int i = 0; i < A.length(); ++i) {
            if (A[i] != B[i]) {
                return i;
            }
        }
        
        return A.length();
    }
};
