/*
    Using backtracking method to solve this problem, however overtime!
*/

class Solution {
    int ans = 0;
    public int numWays(int steps, int arrLen) {
        int locate = 0, csteps = 1, bound = arrLen - 1;
        backTrace(locate, steps, bound, csteps);
        backTrace(locate + 1, steps, bound, csteps);
        return ans;
    }

    public void backTrace(int locate, int steps, int bound, int csteps) {
        if (csteps == steps && locate == 0) {
            ans ++;
            return;
        }
        if (locate < 0 || locate > bound) {
            return;
        }
        if (locate > steps - csteps) {
            return;
        }
        backTrace(locate - 1, steps, bound, csteps + 1);
        backTrace(locate, steps, bound, csteps + 1);
        backTrace(locate + 1, steps, bound, csteps + 1);
        return;
    }

    public static void main(String[] args) {
        Solution test = new Solution();
        System.out.println(test.numWays(7, 7));
    }
}