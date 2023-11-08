class Solution {
private:
    bool flag = true;
public:
    int longestMountain(vector<int>& A) {
        int length = 1;
        int maxLength = 0;
        for (int i = 1; i < A.size(); i++) {
            if (flag) {
                if (A[i] > A[i-1]) {
                    length++;
                } else if (A[i] < A[i-1] && length >= 2){
                    length++;
                    flag = !flag;
                } else {
                    length = 1;
                }
            } else {
                if (A[i] < A[i-1]) {
                    length++;
                } else {
                    flag = !flag;
                    maxLength = (maxLength > length)? maxLength : length;
                    if(A[i] > A[i-1]) length = 2;
                    else length = 1;
                }
            }
        }
        if(length>2 && !flag) maxLength = (maxLength > length)? maxLength : length;
        return maxLength;
    }
};
