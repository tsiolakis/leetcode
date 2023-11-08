class Solution {
    private double distance(int x1, int y1, int x2, int y2) {
        return Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        double dist12, dist13, dist14, dist23, dist24, dist34;
        if((dist12 = distance(p1[0], p1[1], p2[0], p2[1])) == 0) return false;
        if((dist13 = distance(p1[0], p1[1], p3[0], p3[1])) == 0) return false;
        if((dist14 = distance(p1[0], p1[1], p4[0], p4[1])) == 0) return false;
        if((dist23 = distance(p2[0], p2[1], p3[0], p3[1])) == 0) return false;
        if((dist24 = distance(p2[0], p2[1], p4[0], p4[1])) == 0) return false;
        if((dist34 = distance(p3[0], p3[1], p4[0], p4[1])) == 0) return false;
        if (dist12 == dist23 && dist23 == dist34 && dist34 == dist14 && dist24 == dist13)
            return true;
        if (dist13 == dist23 && dist23 == dist24 && dist24 == dist14 && dist12 == dist34)
            return true;
        if (dist12 == dist24 && dist24 == dist34 && dist34 == dist13 && dist23 == dist14)
            return true;

        return false;
    }
}
