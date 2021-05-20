/*
    This is a very clever method, in which we use the property of XOR operations, which is X xor Y xor X = Y.
    This property also can be used as follows: X = 1 ^ 2 ^ 3, Y = 1 ^ 2 ^ 3 ^ 4 ^ 5, then  X ^ Y = 4 ^ 5
    With this property, we can solve this problem easily.
*/

class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length, m = queries.length;
        int[] xors = new int[n + 1];
        int[] ans = new int[m];
        xors[0] = 0;
        for (int i = 0; i < n; i ++) {
            xors[i + 1] = xors[i] ^ arr[i];
        }
        for (int i = 0; i < m; i++) {
            ans[i] = xors[queries[i][0]] ^ xors[queries[i][1] + 1];
        }
        return ans;
    }
}