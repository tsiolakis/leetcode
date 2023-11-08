class Solution {
    public int maxPower(String s) {
        char cBefore = s.charAt(0);
        char c;
        int count = 1;
        int power = 1;
        for (int i = 1; i < s.length(); i++){
            c = s.charAt(i);
            if (c == cBefore)
                count += 1;
            else {
                power = Math.max(count, power);
                count = 1;
            }
            cBefore = c;
        }
        power = Math.max(count, power);
        return power;
    }
}
