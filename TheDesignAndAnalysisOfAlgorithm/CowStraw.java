package exercise1;

import java.util.Scanner;

public class CowStraw {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int C = scanner.nextInt();
        int H = scanner.nextInt();
        int[] Vi = new int[H];
        for (int i = 0; i < H; i ++) {
            Vi[i] = scanner.nextInt();
        }
        int[][] dp = new int[H + 1][C + 1];
        for (int i = 0; i < H + 1; i ++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j < C + 1; j ++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i < H + 1; i ++) {
            for (int j = 1; j < C + 1; j ++) {
                if (j < Vi[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - Vi[i - 1]] + Vi[i - 1]);
                }
            }
        }
        System.out.println(dp[H][C]);
    }
}
