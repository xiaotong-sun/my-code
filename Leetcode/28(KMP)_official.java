/*
给你两个字符串haystack 和 needle ，
请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。
如果不存在，则返回 -1 。
链接：https://leetcode-cn.com/problems/implement-strstr

利用 KMP算法 解决该题
关键点是部分匹配表PMT(partial match table)的构建。
 */
class Solution {
    public int strStr(String  haystack, String needle) {
        int m = haystack.length();
        int n = needle.length();
        if (n == 0) {
            return 0;
        }
        int[] next = new int[n];

        // 构建PMT
        for (int i = 1, j = 0; i < n; i ++) {
            while (j > 0 && needle.charAt(i) != needle.charAt(j)) {
                j = next[j - 1];
            }
            if (needle.charAt(j) == needle.charAt(i)) {
                j ++;
            }
            next[i] = j;
        }

        // 查找字串位置
        for (int i = 0, j = 0; i < m; i ++) {
            while (j > 0 && haystack.charAt(i) != needle.charAt(j)) {
                j = next[j - 1];
            }
            if (haystack.charAt(i) == needle.charAt(j)) {
                j ++;
            }
            if (j == n) {
                return i - n + 1;
            }
        }

        // 没有查找到
        return -1;
    }

    public static void main(String[] args) {
        Solution test = new Solution();
        int ans = test.strStr("hello", "lo");
        System.out.println(ans);
    }
}