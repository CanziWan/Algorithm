70.爬楼梯
题目：
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

示例 1：
输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。

1 阶 + 1 阶
2 阶
示例 2：
输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。

1 阶 + 1 阶 + 1 阶
1 阶 + 2 阶
2 阶 + 1 阶
提示：
1 <= n <= 45

解题思路：
这是一个经典的动态规划问题，可以用斐波那契数列的思想来解决。因为每次只能爬1阶或2阶，那么到达第n阶的方法数等于到达第(n-1)阶的方法数加上到达第(n-2)阶的方法数。

步骤：
1.确定状态：
令 dp[i] 表示到达第 i 阶的方法数。
2.状态转移方程：
对于第 i 阶，可以从第 i-1 阶迈一步或者从第 i-2 阶迈两步到达。因此，状态转移方程为：
dp[i]=dp[i−1]+dp[i−2]
3.初始化：
dp[1] = 1，因为只有一种方法到达第1阶。
dp[2] = 2，因为有两种方法到达第2阶（1阶+1阶 或者 2阶）。
4.计算结果：
从第3阶开始，根据状态转移方程计算每一阶的方法数，直到第 n 阶。

复杂度分析：
时间复杂度是 O(n)，空间复杂度也是 O(n)。


// 实现代码：

class Solution {
    public int climbStairs(int n) {
        // 特殊情况处理
        if (n == 1) {
            return 1;
        }
        
        // 初始化 dp 数组
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;

        // 根据状态转移方程计算 dp[i]
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
}
