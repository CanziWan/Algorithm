//#1 两数之和



//## 解题思路

/*
暴力解法：用两层for循环遍历数组，注意一下循环的边界取值问题；
          然后用if语句判断，
          若找到符合题目条件的两个数，则用malloc函数申请内存空间，将符合条件的两个数的数组下标保存到结果数组中，
          若两层循环后找不到题目要求的两个数，则返回NULL。
*/



//## 代码

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for(int i = 0; i < numsSize; i++){
        int x = nums[i];
        for(int j = i + 1; j < numsSize; j++){
            if(nums[j] == target - x){
                int* ret = (int*)malloc(sizeof(int)*2);
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
