class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = 0;
        int j = 0;
        int k = 0;
        //create a copyOfNums1 so we can change nums1
        int[] copyOfNums1 = new int[m];
        for (int index = 0; index < m; index++)
            copyOfNums1[index] = nums1[index];
        // there is no reason to copy nums2

        while (j < m && k < n) {

            if (copyOfNums1[j] <= nums2[k]) {
                nums1[i] = copyOfNums1[j];
                j++;
            } else {
                nums1[i] = nums2[k];
                k++;
            }
            i++;
        }
        while (j < m) {
            nums1[i] = copyOfNums1[j];
            j++;
            i++;
        }
        while (k < n) {
            nums1[i] = nums2[k];
            k++;
            i++;
        }
    }
}
