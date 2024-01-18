#include <stdio.h>

// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Example 1:

// Input: nums = [2,2,1]
// Output: 1
// Example 2:

// Input: nums = [4,1,2,1,2]
// Output: 4

int singleNumber(int* nums, int numsSize) {
    int target = nums[0];
    for (int counter = 1; counter < numsSize; ++counter) {
        target ^= nums[counter];
    }

    return target;
}

int main() {
    int nums[] = {2, 4, 6, 2, 4};
    int sn = singleNumber(nums, sizeof(nums) / sizeof(nums[0]));
    printf("%zu\n", sizeof(nums) / sizeof(nums[0]));
    printf("%d\n", sn);
    return 0;
}