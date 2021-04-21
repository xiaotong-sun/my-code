package exercise1;

import java.util.Arrays;
import java.util.Scanner;

public class LongestCommonSubsequence {
    public static void LCS(int i, int j, String string1, int[][] b) {
        if (i == 0 || j ==0) {
            return;
        }
        if (b[i][j] == 1) {
            LCS(i - 1, j - 1, string1, b);
            System.out.print(string1.charAt(i - 1));
        } else if (b[i][j] == 2) {
            LCS(i - 1, j, string1, b);
        } else {
            LCS(i, j - 1, string1, b);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入第一个字符串序列：");
        String string1 = scanner.next();
        System.out.print("请输入第二个字符串序列：");
        String string2 = scanner.next();
        int m = string1.length() + 1;
        int n = string2.length() + 1;
        int[][] dp = new int[m][n];
        int[][] b = new int[m][n];
        for (int i = 0; i < n; i ++) {
            dp[0][i] = 0;
            b[0][i] = 0;
        }
        for (int i = 0; i < m; i ++) {
            dp[i][0] = 0;
            b[i][0] = 0;
        }
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                if (string1.charAt(i - 1) == string2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    b[i][j] = 1;
                } else if (dp[i - 1][j] >= dp[i][j - 1]){
                    dp[i][j] = dp[i - 1][j];
                    b[i][j] = 2;
                } else {
                    dp[i][j] = dp[i][j - 1];
                    b[i][j] = 3;
                }
            }
        }
        for (int i = 0; i < m; i ++) {
            System.out.println(Arrays.toString(dp[i]));
        }
        System.out.println("最长公共子序列长度为：" + dp[m - 1][n - 1]);
        System.out.print("最长公共子序列是：");
        LCS(m - 1, n - 1, string1, b);
    }
}
