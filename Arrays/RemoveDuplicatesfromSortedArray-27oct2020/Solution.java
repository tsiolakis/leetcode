class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        if (len == 0) return len;
        int i = 1;
        int val = nums[0];
        while (i < len) {
            if (nums[i] == val) {
                len -= 1;
                for (int j = i; j < len; j++) {
                    nums[j] = nums[j+1];
                }
                continue;
            }
            val = nums[i];
            i++;
        }
        return len;
    }
}

class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length == 0)
            return nums.length;

        int j=0;
        for(int i=0; i+1<nums.length; i++){
            if(nums[i] != nums[i+1]){
                nums[j++] = nums[i];
            }
        }
        nums[j++] = nums[nums.length-1];
        return j;
    }
}
