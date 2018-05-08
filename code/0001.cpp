class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int,int> numIdxMap;
        int idx = 0;
        
        for (const auto &num : nums) {
            numIdxMap.insert(make_pair(num, idx++));
        }
        
        idx = 0;
        for (const auto &num : nums) {
            if (numIdxMap.find(target - num) != numIdxMap.end()
               && numIdxMap[target - num] != idx) {
                return {idx, numIdxMap[target - num]};
            }
            ++idx;
        }
    }
};

/*
Complexity : O(N logN)

Using unordered_map can reduce the time complesity.

Just be careful on this test case :
nums : [3, 4, 2]
target : 6
*/
