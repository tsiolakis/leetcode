class Solution {
    public int[][] flipAndInvertInage(int[][] A) {
        int n = A.length;
        int temp; // used in swap routine
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n/2; j++) {
                temp = A[i][j];
                A[i][j] = A[i][n-1-j];
                A[i][n-1-j] = temp;
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                A[i][j] = (A[i][j] == 1) ? 0 : 1;
        return A;
    }
}
