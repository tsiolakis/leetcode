import java.util.*;
class Solution {
    int []sqArr;
    int j;
    boolean flag = true;

    public boolean winnerSquareGame(int n) {
        System.out.println("game(" + n + ")"    );

        if (n == 0){
            System.out.println("end of game(0) returned " + false);
            return false;
        }
        if (flag) { // find all playable numbers
            int i = 0;
            sqArr = new int[(int)Math.floor(Math.sqrt(n))]; //floor(sqrt(n)) is the number of perfect squares below n
            while ((i+1) * (i+1) <= n){
                i++;
                sqArr[i-1] = i*i;
            }
            j = sqArr.length - 1;
            flag = false;
        }
        //stupid way to put j in the correct spot
        while (j != sqArr.length - 1 && sqArr[j+1] <= n) {
            j++;
        }
        while (sqArr[j] > n) {
            j--;
        }
        System.out.println("from game(" + n + ") calling: game(" + (n - sqArr[j]) + ")");
        int k = j; //this is so stupid i am genuinely ashamed
        boolean retVal = winnerSquareGame(n - sqArr[j]);
        j = k;
        while (retVal && j > 0) { //if this play leads to a game which is won by opponent then skip play
            j--;
            k = j;
            System.out.println("from game(" + n + ") calling: game(" + (n - sqArr[j]) + ")");
            retVal = winnerSquareGame(n - sqArr[j]);
            j = k;
        }
        System.out.println("end of game(" + n + ")" + " returned " + !retVal);

        return(!retVal);
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
