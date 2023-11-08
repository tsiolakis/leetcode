class Solution {
private:
    void swapInt(int&a, int&b) {
        int temp = a;
        a = b;
        b= temp;
    }
    bool permutationIsAlreadyIn(std::vector<int>& v, std::vector<std::vector<int>>& permutations) {
        bool found = false;
        for (std::vector<int> permutation : permutations) {
            if (std::equal(permutation.begin(), permutation.begin() + permutation.size(), v.begin())){
                found = true;
                break;
            }
        }
        return found;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::vector<std::vector<int>> permutations;
        std::vector<int> v;
        for (int num : nums) {
            v.push_back(num);
        }
        permutations.push_back(v);
        
        return permutations;
    }
};
