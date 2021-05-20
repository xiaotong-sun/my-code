import java.util.Arrays;

class Solution {
    public int shipWithinDays(int[] weights, int D) {
        int min = Arrays.stream(weights).max().getAsInt();
        int max = Arrays.stream(weights).sum();
        while (min < max) {
            int mid = min + max >> 1;
            if (Days(weights, D, mid)) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        return min;
    }

    public boolean Days(int[] weights, int D, int lowWeight) {
        int days = 0;
        int temp = lowWeight;
        int ptr = 0;
        while (ptr < weights.length) {
            if (temp - weights[ptr] >= 0) {
                temp -= weights[ptr];
                ptr ++;
            }
            // ptr == weights.length 的作用是当ptr = weights.length时，能够使day + 1
            if (ptr == weights.length || temp - weights[ptr] < 0){
                days ++;
                temp = lowWeight;
            }
            if (days > D) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Solution test = new Solution();
        int[] weights = {10,50,100,100,50,100,100,100};
        int D = 5;
        System.out.println(2 + 5 >> 1);
        System.out.println(test.shipWithinDays(weights, D));
    }
}