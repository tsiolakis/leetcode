#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    bool find132pattern(vector<int>& nums);
};

bool Solution::find132pattern(vector<int>& nums) {
    if (nums.size() < 3)
        return false;

    int min = num[0];
    int g;
    bool flag = true;
    int i = 1;
    while (flag) {
        while (i < v.size()) {
            if (arr[i] < min) {
                min = arr[i];
                i++;
                break;
            }
            if (arr[i] > min + 1) {
                g = arr[i];
                i++;
                flag = false;
                break;
            }
        }
    }
    while (i < v.size()) {
        if (arr[i] > min && arr[i] < g) {
            return true;
        } else if (arr[i] > g) {
            g = arr[i];
            i++;
        } else if (arr[i] < min){
            if (find132pattern()) {
                /* code */
            }
        }
    }

}
int main() {
    vector<int> v = {3,1,4,2};
    Solution sol;
    bool answer = sol.find132pattern(v);
    std::cout << answer << '\n';

    return 0;
}
