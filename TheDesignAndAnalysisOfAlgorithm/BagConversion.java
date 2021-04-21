package exercise1;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class BagConversion {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();  // 重量
        int n = scanner.nextInt();  // 物品个数
        int[][] temp = new int[n][3];
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < 3; j ++) {
                temp[i][j] = scanner.nextInt();
            }
        }
        Set<Integer> set = new HashSet<>();
        int count = 0;
        for (int i = 0; i < n; i ++) {
            if (set.add(temp[i][2])) {
                count ++; // 统计组数
            }
        }
        int[][] dp = new int[count + 1][m + 1];
        for (int i = 1; i < count + 1; i ++) {
            for (int j = 1; j < m + 1; j ++) {
                int k = i;
                for (int f = 0; f < n; f ++) {
                    if (temp[f][2] == k) {
                        if (temp[f][0] > j) {
                            dp[i][j] = Math.max(dp[i - 1][j], dp[i][j]);  // 注意
                        } else {
                            dp[i][j] = Math.max(dp[i - 1][j - temp[f][0]] + temp[f][1], Math.max(dp[i][j],dp[i - 1][j]));
                        }
                    }
                }
            }
        }
        for (int i = 0; i < count + 1; i ++) {
            System.out.println(Arrays.toString(dp[i]));
        }
        System.out.println(dp[count][m]);
    }
}
