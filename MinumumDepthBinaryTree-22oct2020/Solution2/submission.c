bool find132pattern(int* nums, int numsSize){
    if (numsSize < 3)
        return false;

    int min = nums[0];
    int g;
    bool flag = true;
    int i = 1;
    while (i < numsSize) {
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
    return false;
}
