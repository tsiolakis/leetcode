class Solution {
    public int findNumbers(int[] nums) {
        int count;
        int evenCount= 0;
        for (int element : nums) {
            count = 0;
            do {
                element = element / 10;
                count += 1;
            } while (element != 0);
            if ((count & 1) == 0) {
                evenCount += 1;
            }
        }
    return evenCount;
    }
}


// 100% solution
class Solution {
    public int findNumbers(int[] nums) {
        int count=0;
        for(int i=0;i<nums.length;i++){
            if( ((int) Math.log10(nums[i]))%2==1){
                count++;
            }
        }
        return count;
    }
}
