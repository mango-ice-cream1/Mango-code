
//力扣初级算法-移动零
int* moveZeroes(int* nums, int numsSize) {

    if (nums == NULL)
    {
        return 0;
    }
    int t1 = 0, t2 = 0;
    while (t2 < numsSize)
    {
        if (nums[t2] != 0)
        {
            nums[t1] = nums[t2];
            t1++;

        }
        t2++;
    }
    while (t1 < numsSize)
    {
        nums[t1++] = 0;
    }
    return nums;
}




