#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define n 7

bool find132pattern(int* nums, int numsSize){
    int j = 0;
    while (j < numsSize) {
        printf("%d\t", nums[j]);
        j++;
    }
    printf("\n");
    if (numsSize < 3)
        return false;



    int min = nums[0];
    int g;
    bool flag = true;
    int i = 1;
    while (i < numsSize) {
        printf("%d\n",i);
        if (nums[i] < min) {
            min = nums[i];
        }
        if (nums[i] > min + 1) {
            g = nums[i];
            i++;
            flag = false;
            break;
        }
        i++;
    }
    if (flag == true) {
        //didn't find g
        return false;
    }
    while (i < numsSize) {
        if (nums[i] > min && nums[i] < g) {
            printf("first found:%d\t%d\t%d\t", min, g, nums[i]);
            return true;
        } else if (nums[i] > g) {
            g = nums[i];
        } else if (nums[i] < min) {
            if (find132pattern(nums + i, numsSize - i) == true) {
                return true;
            }
        }
        i++;
    }
    printf("nothing was found\n");
    return false;
}

int main() {
    int* v;
    v = (int*)malloc(n*sizeof(int));
    v[0] = 1;
    v[1] = 2;
    v[2] = -1;
    v[3] = 4;
    v[4] = 8;
    v[5] = -5;
    v[6] = 7;

    bool answer = find132pattern(v, n);
    if (answer == true) {
        printf("FOUND IT");
    } else {
        printf("NOPE");
    }

    return 0;
}
