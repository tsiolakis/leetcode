import java.util.*;
class Solution {
    byte lookup[];
    boolean  lookupIsNotInitialised = true;
    final byte NIL = -1;

    void initialise(int n) {
        lookup = new byte[n];
        lookup[0] = 0;
        for (int i = 1; i < n; i++)
            lookup[i] = NIL;
        lookupIsNotInitialised = false;
    }

    public boolean winnerSquareGame(int n) {
        if (lookupIsNotInitialised) {initialise(n);}
//        if (n == 0) {return false;}

        boolean retVal;
        int i = 1;
        do {
            if (lookup[(n - i*i)] == NIL) {
                retVal = winnerSquareGame(n - i*i);
                if (retVal)
                    lookup[(n - i*i)] = 1;
                else
                    lookup[(n - i*i)] = 0;
            } else if (lookup[(n - i*i)] == 1) {
                retVal = true;
            } else {
                retVal = false;
            }
            i++;
        } while (retVal && i * i <= n);

        return !retVal;

    }
}
public static void main(String[] args) {
    Solution sol = new Solution();
    Scanner scan = new Scanner(System.in);
    int x = scan.nextInt();

    if (sol.winnerSquareGame(x))
        System.out.println("Alice won!");
    else
        System.out.println("Boberman won...");
}
