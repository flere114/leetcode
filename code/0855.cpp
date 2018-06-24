class ExamRoom {
public:
    ExamRoom(int _N) : N(_N) {
    }
    
    int seat() {
        if (occupied.empty()) {
            occupied.push_back(0);
            return 0;
        }
        
        int pos = 0, gap = 0;
        if ((occupied[0] - 0) >= (N-1 - occupied[occupied.size()-1])) {
            pos = 0;
            gap = occupied[0];
        } else {
            pos = N-1;
            gap = N-1 - occupied[occupied.size()-1];
        }
        
        // check middle of occupied[i-1] & occupied[i]
        for (int i=1; i<occupied.size(); ++i) {
            int tmp = occupied[i-1] + occupied[i];
            
            // find the middle
            if (tmp & 1) {
                --tmp;
            }
            tmp /= 2;
            
            if (tmp - occupied[i-1] > gap) {
                pos = tmp;
                gap = tmp - occupied[i-1];
            } else if (tmp - occupied[i-1] == gap && tmp < pos) {
                pos = tmp;
            }
        }
        
        occupied.insert(upper_bound(occupied.begin(), occupied.end(), pos), pos);
        return pos;
    }
    
    void leave(int p) {
        occupied.erase(lower_bound(occupied.begin(), occupied.end(), p));
    }
private:
    int N;
    vector <int> occupied;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
