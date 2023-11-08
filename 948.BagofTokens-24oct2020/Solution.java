import java.util.Arrays;
import java.util.stream.*;

class Solution {
    public int bagOfTokensScore(int[] tokens, int P) {
        if (tokens.length == 0)
            return 0;

        Arrays.sort(tokens);
        if (P < tokens[0])
            return 0;
        else
            P -= tokens[0]; //score is set to 1 just a few lines below

        int sum = IntStream.of(tokens).sum() - tokens[0]; //tokens[0] has already been played face up
        int score = 1;
        int i = 1;
        int j = tokens.length - 1;
        while (P < (sum - tokens[j]) && i != j) {

            if (score > 0) { //play face down
                P += tokens[j];
                sum -= tokens[j];
                score -= 1;
                j--;
            } else if (P >= tokens[i]) { //play face up
                P -= tokens[i];
                sum -= tokens[i];
                score += 1;
                i++;
            }
        }
        //There is no reason to keep caluclating the remaing sum
        while (i <= j && P >= tokens[i]) { // just play face up from now on to get the best score
            P -= tokens[i];
            score += 1;
            i++;
        }
        return score;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] bag = {};
        int power = 50;
        System.out.println(sol.bagOfTokensScore(bag, power));
    }
}
