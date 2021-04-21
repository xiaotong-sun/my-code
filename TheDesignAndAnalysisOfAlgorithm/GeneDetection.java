package exercise1;

import java.util.Arrays;
import java.util.Scanner;

public class GeneDetection {
    public static void main(String[] args) {
        int[][] temp = {{5, -1, -2, -1, -3}, {-1, 5, -3, -2, -4}, {-2, -3, 5, -2, -2}, {-1, -2, -2, 5, -1}, {-3, -4, -2, -1, 0}};
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt(); // 行
        String string1 = scanner.next(); // 行串
        int n = scanner.nextInt(); // 列
        String string2 = scanner.next(); // 列串

        int[][] dp = new int[m + 1][n + 1];
        // 边界条件
        dp[0][0] = 0;
        for (int i = 1; i < m + 1; i ++) {
            dp[i][0] = dp[i - 1][0] + search('-', string1.charAt(i - 1), temp);
        }
        for (int i = 1; i < n + 1; i ++) {
            dp[0][i] = dp[0][i - 1] + search('-', string2.charAt(i - 1), temp);
        }

        // 状态转移
        for (int i = 1; i < m + 1; i ++) {
            for (int j = 1; j < n + 1; j ++) {
                dp[i][j] = Math.max(dp[i - 1][j - 1] + search(string1.charAt(i - 1), string2.charAt(j - 1), temp),
                        Math.max(dp[i][j - 1] + search(string2.charAt(j - 1), '-', temp), dp[i - 1][j] + search(string1.charAt(i - 1), '-', temp)));
            }
        }
//        for (int i = 0; i < m + 1; i ++) {
//            System.out.println(Arrays.toString(dp[i]));
//        }
        System.out.println(dp[m ][n]);
    }

    public static int search(char a, char b, int[][] temp) {
        int x, y;
        if (a == 'A') {
            x = 0;
        }else if (a == 'C') {
            x = 1;
        }else if (a == 'G') {
            x = 2;
        }else if (a == 'T') {
            x = 3;
        }else {
            x = 4;
        }
        if (b == 'A') {
            y = 0;
        }else if (b == 'C') {
            y= 1;
        }else if (b == 'G') {
            y = 2;
        }else if (b == 'T') {
            y = 3;
        }else {
            y = 4;
        }
        return temp[x][y];
    }
}
