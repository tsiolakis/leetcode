class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxDist;
        int lastCoronaSeat;
        int i;
        bool exitg1;
        int b_lastCoronaSeat;
        int i0;
        unsigned int b_i;
        lastCoronaSeat = 1;
        maxDist = 0;
        i = 0;
        exitg1 = false;
        while ((!exitg1) && (i <= seats.size() - 1)) {
          if (seats[i] == 1) {
            lastCoronaSeat = 1 + i;
            maxDist = i;
            exitg1 = true;
          } else {
            i++;
          }
        }

        b_lastCoronaSeat = lastCoronaSeat;
        i0 = seats.size() - lastCoronaSeat;
        for (i = 0; i <= i0; i++) {
          b_i = (unsigned int)b_lastCoronaSeat + i;
          if (seats[(int)b_i - 1] == 1) {
            if (std::floor(((int)b_i - lastCoronaSeat) / 2.0) > maxDist) {
              maxDist = ((int)b_i - lastCoronaSeat) / 2.0;
            }

            lastCoronaSeat = (int)b_i;
          }
        }
        if ((seats[seats.size() - 1] == 0) && (seats.size() -
             lastCoronaSeat > (int)maxDist)) {
          maxDist = seats.size() - lastCoronaSeat;
        }
        return maxDist;
    }
};
