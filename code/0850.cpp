/*
 * It's a classic coordinate compression problem.
 */

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector <int> vx, vy;
        map <int,int> convX, convY;  // original x,y to new x,y
        map <int,int> revX, revY;  // new x,y to original x,y
        
        // collect all cordinate
        for (int i=0; i<rectangles.size(); ++i) {
            vx.push_back(rectangles[i][0]);
            vx.push_back(rectangles[i][2]);
            vy.push_back(rectangles[i][1]);
            vy.push_back(rectangles[i][3]);
        }
        
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());
        
        vx.erase(unique(vx.begin(), vx.end()), vx.end());
        vy.erase(unique(vy.begin(), vy.end()), vy.end());
        
        // coordinate compression
        for (int i=0; i<vx.size(); ++i) {
            convX[vx[i]] = i;
            revX[i] = vx[i];
        }
        for (int i=0; i<vy.size(); ++i) {
            convY[vy[i]] = i;
            revY[i] = vy[i];
        }
        
        // draw rectangle
        bool occupy[405][405] = {0};  // there are at most 400 different x coordinate
        for (int i=0; i<rectangles.size(); ++i) {
            int x1 = convX[rectangles[i][0]];
            int x2 = convX[rectangles[i][2]];
            int y1 = convY[rectangles[i][1]];
            int y2 = convY[rectangles[i][3]];
            
            for (int x=x1; x<x2; ++x) {
                for (int y=y1; y<y2; ++y) {
                    occupy[x][y] = true;
                }
            }
        }
        
        // cal each cell
        long long ans = 0;
        for (int x=0; x<405; ++x) {
            for (int y=0; y<405; ++y) {
                if (occupy[x][y]) {
                    long long length = revX[x+1] - revX[x];
                    long long width = revY[y+1] - revY[y];
                    long long area = (length * width) % MOD;
                    ans = (ans + area) % MOD;
                }
            }
        }
        
        return ans;
    }
private:
    const int MOD = 1000000000 + 7;
};
