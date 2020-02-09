class Solution {
public:
    /**
     * @param k: An integer
     * @param n: An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) {
        int total = 0, a;
        if(k == 0) {
            total = 1;
        }
        for(int i = 0; i <= n; i ++) {
            a = i;
            while(a != 0) {
                if(a % 10 == k) {
                    total ++;
                }
                a /= 10;
            }
        }
        return total;
    }
};
