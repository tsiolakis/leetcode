//doesnt work..
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<double>> n;
    int ki, kj;
    bool notDone = true;
    bool pour(double amount, int i, int j) {
        if (notDone && i < n.size() && j < n[i].size() && amount > 0){
                if (n[i][j] == 1) {
                    if (i == ki && j == 0)
                        return false;

                    if (n[i+1].size() >= n[i].size()) {
                        if (notDone && i+1 < n.size() && j < n[i+1].size() && amount > 0)
                            notDone = pour(amount/2, i+1, j);
                        if (notDone && i+1 < n.size() && j+1 < n[i+1].size() && amount > 0)
                            notDone = pour(amount/2, i+1, j+1);
                    } else {
                        if (notDone && i+1 < n.size() && j-1 > 0 && amount > 0)
                            notDone = pour(amount/2, i+1, j-1);
                        if (notDone && i+1 < n.size() && j < n[i+1].size() && amount > 0)
                            notDone = pour(amount/2, i+1, j);
                    }
                }
                else {
                    n[i][j] += amount;
                    if (n[i][j] > 1.0) {
                        amount =  n[i][j] - 1;
                        n[i][j] = 1;
                        if (i == ki && j == 0)
                            return false;

                        if (n[i+1].size() >= n[i].size()) {
                            notDone = pour(amount/2, i+1, j);
                            if(j+1 < n[i+1].size()){notDone = pour(amount/2, i+1, j+1);}
                        } else {
                            if (j-1 > 0){notDone = pour(amount/2, i+1, j-1);}
                            if (j < n[i+1].size()){notDone = pour(amount/2, i+1, j);}
                        }
                    }
                }
            return true;
        }
        return false;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured == 0) {
            return 0;
        }

        ki = query_row;
        kj = query_glass;
        n = vector<vector<double>>(ki+1);
        int min = 0;
        int max = 0;
        for (int i = 0; i < ki+1; i++) {
            if (i <= kj)
                max = i;
            else
                max = kj;
            if (i <= ki - kj)
                min = 0;
            else
                min = kj + i - ki;
            n[i] = vector<double>(max-min +1);
            for (int j = 0; j < n[i].size(); j++) {
                n[i][j] = 0;
            }

        }
        pour(poured, 0, 0);
        return n[query_row][0];
    }
};
int main(int argc, char const *argv[]) {
    Solution* sol = new Solution();
    double ans = sol->champagneTower(2,1,1);
    std::cout << "asnwer: "<< ans << '\n';
    return 0;
}
