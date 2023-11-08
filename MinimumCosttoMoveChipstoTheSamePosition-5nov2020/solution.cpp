class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int length = position.size();
        int chipsInEvenPositions = 0;
        int chipsInOddPositions = 0;
        for (int i = 0; i < length; i++) {
            if (position[i] & 1)
                chipsInOddPositions += 1;
            else
                chipsInEvenPositions += 1;
        }

        return ((chipsInEvenPositions < chipsInOddPositions)? chipsInEvenPositions : chipsInOddPositions);
    }
};
