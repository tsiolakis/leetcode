#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> retVector;
        if (nums.size() == 0)
            return retVector;

        int cut = 0;
        int i;
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1] + 1)
                continue;
            if (i > cut + 1)
                retVector.push_back(to_string(nums[cut]) + "->" + to_string(nums[i-1]));
            else
                retVector.push_back(to_string(nums[cut]));
            cut = i;
        }
        if (i > cut + 1)
            retVector.push_back(to_string(nums[cut]) + "->" + to_string(nums[i-1]));
        else
            retVector.push_back(to_string(nums[cut]));
        return retVector;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> v = {0, 2, 4, 6, 8, 10, 12, 14, 16};
    Solution* sol = new Solution();
    vector<string> answer = sol->summaryRanges(v);
    for (auto it : answer)
        std::cout << it << '\n';

    return 0;
}
