class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int count = 0;
        int maxCount = 0;
        for (int element : nums) {
            if (element == 1)
                count += 1;
            else {
                maxCount = Math.max(count, maxCount);
                count = 0;
            }
        }
        return maxCount;
    }
}
