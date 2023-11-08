class Solution {
private:
    int calculateDividedSum(vector<int>& v, int divisor) {
        int sum = 0;
        for (int value : v)
            sum += (value % divisor)>0?(value/divisor)+1:(value/divisor);
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int max = nums[0];
        for (unsigned int i = 1; i < nums.size(); i++)
            if (max < nums[i])
                max = nums[i];
        for (int i = max; i > 0; i--) {
            if (calculateDividedSum(nums, i) <= threshold) {
                return i;
            }
        }
        return 1;
    }
};
