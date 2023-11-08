#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define print(cont, iter) iter = cont.begin(); while(iter != cont.end()) {std::cout << *iter++ << '\t';} std::cout << std::endl;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> asteroidsList(asteroids.begin(), asteroids.end());
        vector<int> returnVector;
        list<int>::iterator i, j;

        for (i = asteroidsList.begin(); i != asteroidsList.end();) {
            if (asteroidsList.size() == 0) {
                return returnVector;
            } else if (asteroidsList.size() == 1) {
                returnVector.push_back(asteroidsList.front());
                return returnVector;
            }
            j = i;
            j++;

            if (*i > 0 && *j < 0) {
                if ((abs(*i) > abs(*j))) {
                    j = asteroidsList.erase(j);
                } else if ((abs(*i) < abs(*j))) {
                    i = asteroidsList.erase(i);

                    if (i != asteroidsList.begin() && j != asteroidsList.end())
                        i--;
                } else {
                    j = asteroidsList.erase(j);
                    i = asteroidsList.erase(i);
                    if (i != asteroidsList.begin()  && i != asteroidsList.end() && j != asteroidsList.end())
                        i--;
                }
            }
            else if (i != asteroidsList.end()) {
                i++;
            }


        }

        for (i = asteroidsList.begin(); i != asteroidsList.end(); i++) {
            returnVector.push_back(*i);
        }
        return returnVector;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> v, u;
    std::vector<int>::iterator it;
    v.push_back(10);
    v.push_back(2);
    v.push_back(-5);




    print(v ,it);
    u = sol.asteroidCollision(v);
    print(u ,it);

    return 0;
}
