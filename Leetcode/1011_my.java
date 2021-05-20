import java.util.Arrays;

class Solution {
    public int shipWithinDays(int[] weights, int D) {
        int ptr = 0;
        int ans = Arrays.stream(weights).max().getAsInt();
        int days = D + 1; // 使之能够进入循环
        while (days > D) {
            days = 0;
            int temp = ans;
            while (ptr < weights.length) {
                if (temp - weights[ptr] >= 0) {
                    temp -= weights[ptr];
                    ptr ++;
                }
				// ptr == weights.length 的作用是当ptr = weights.length时，能够使day + 1
                if (ptr == weights.length || temp - weights[ptr] < 0){
                    days ++;
                    temp = ans;
                }
                if (days > D) {
                    ptr = 0;
                    break;
                }
            }
            ans ++;
        }
        return ans - 1;
    }

    public static void main(String[] args) {
        Solution test = new Solution();
        int[] weights = {1,2,3,1,1};
        int D = 4;
        System.out.println(test.shipWithinDays(weights, D));
    }
}