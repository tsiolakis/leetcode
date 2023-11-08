class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        if (poured <= 1 + (2 << query_row)) { //if poured<= 1+2^i
            return 1;
        }

        int lastFullRow = query_row;
        while (poured > 1 + (2 << lastFullRow)) {
            lastFullRow -= 1;
        }

        
        return -1;
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol. champagneTower(7, 2, 2));
    }
}
