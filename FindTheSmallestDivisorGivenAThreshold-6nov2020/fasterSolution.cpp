class Solution {
private:
    int calculateDividedSum(vector<int>& v, int divisor) {
        if(divisor == 0)
            return 1000001;
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
        int min = 1;
        int mid = (max-min)/2;
        int sum, sum2;
        while(true) {
            sum = calculateDividedSum(nums, mid);
            sum2 = calculateDividedSum(nums, mid-1);
            if (sum <= threshold){
                if (sum2 > threshold)
                    return mid;
                max = mid;
            } else {
                min = mid;
            }
            mid = (max+min)/2;

        }
        return 1;
    }
};
