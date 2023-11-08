#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> retVector;
        int cut = nums.size() - 1;
        int diff = nums[cut] - nums[0];
        int start = 0;
        while (start < nums.size()) {
            if (cut == diff) {
                cut+=1;
                diff = nums[cut] - nums[start];
                while(cut == diff) {
                    cut+=1;
                    diff = nums[cut] - nums[start];
                }
                cut-=1;
                diff = nums[cut] - nums[start];
                if (diff == 0)
                    retVector.push_back(to_string(nums[start]));
                else
                    retVector.push_back(to_string(nums[start]) + "->" + to_string(nums[cut]));
                start = cut + 1;
                cut = (start + nums.size()) / 2;
                diff = nums[cut] - nums[start];
                continue;
            }
            cut = start + cut / 2;
            diff = nums[cut] - nums[start];
        }
        return retVector;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> v = {0, 1, 3, 4, 6, 7};
    Solution* sol = new Solution();
    vector<string> answer = sol->summaryRanges(v);
    for (auto it : answer)
        std::cout << it << '\n';

    return 0;
}
