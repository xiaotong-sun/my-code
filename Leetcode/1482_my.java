/*
	Using the idea of binary-search to find the minium days.
	If a problem can be solved in binary-search method, it has the following characteristic:
		it can be divided into two blocks.
		In the first block, the answer of the problem is false, so we need to set 'right = mid / mid + 1'.
		In the second block, the answer of the problem is true, so we need to set 'left = mid / mid - 1'.
*/

import java.util.Arrays;
import java.util.Collections;

class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        if (m * k > bloomDay.length) {
            return -1;
        }
        int low = Arrays.stream(bloomDay).min().getAsInt();
        int high = Arrays.stream(bloomDay).max().getAsInt();
        while (low < high) {
            int mid = (low + high) >> 1;
            if (check(bloomDay, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
	
	//  check the Day whether in these days we can collect enough flowers or not.
    public  boolean check(int[] bloomDay, int m, int k, int days) {
        int n = bloomDay.length;
        int[] temp = new int[n];
        for (int i = 0; i < n; i ++) {
            if (bloomDay[i] <= days) {
                temp[i] = 0;
            } else {
                temp[i] = 1;
            }
        }
        int ptr = 0, count = 0;
        while (ptr < n) {
            if (temp[ptr] == 0){
                ptr ++;
                count ++;
            } else {
                ptr ++;
                count = 0;
            }
            if (count == k) {
                m --;
                count = 0;
            }
        }
        if (m <= 0) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Solution test = new Solution();
        int[] bloomDay = {1,10,3,10,2};
        System.out.println(test.minDays(bloomDay, 3, 2));
    }
}