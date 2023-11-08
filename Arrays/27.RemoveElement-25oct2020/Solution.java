class Solution {
    public int removeElement(int[] nums, int val) {
        int len = nums.length;
        int i = 0;
        while (i < len) {
            if (nums[i] == val) {
                len -= 1;
                for (int j = i; j < len; j++) {
                    nums[j] = nums[j+1];
                }
                continue;
            }
            i++;
        }
        return len;
    }
}
