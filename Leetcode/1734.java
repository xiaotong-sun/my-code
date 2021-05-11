/*
    In this problem, the first important thing is how to compute the first number of the perm-Array.
    From the description of the prmblem, we know that the numbers in perm-Array is between 1 and n.
    So, we can enumerate every num between 1 and n as the first number of the perm_Array, and check whether the first number is correct.
    The definition of Correct is that, if we know the first number of perm-Array, then we can compute all the numbers in the perm-Array, if all
    of the numbers are between 1 and n, we claim that the first number is Correct.
*/

import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] decode(int[] encoded) {
        int n = encoded.length + 1;
        int[] ans = new int[n];
        for (int i = 1; i <= n; i ++) {
            List<Integer> list = new ArrayList<>();
            list.add(i);
            if (checkFirst(i, list, encoded)) {
                for (int j = 0; j < n; j ++) {
                    ans[j] = list.get(j);
                }
                break;
            }
        }
        return ans;
    }

    public boolean checkFirst(int x, List<Integer> list, int[] encode) {
        for (int i = 0; i < encode.length; i ++) {
            int n = encode[i] ^ list.get(i);
            if (n <= (encode.length + 1) && n != 0) {
                list.add(n);
            } else {
                return false;
            }
        }
        return true;
    }
}