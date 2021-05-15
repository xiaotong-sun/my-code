class Solution {
    public int romanToInt(String s) {
        // 预处理
        char[] temp = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int[]  value = {1, 5, 10, 50, 100, 500, 1000};
        char[] charOfs = s.toCharArray();
        int len = charOfs.length;
        int[] toValue = new int[len];
        int ans = 0;

        // 生成toValue数组
        for (int i = 0; i < len; i ++) {
            for (int j = 0; j < 7; j ++) {
                if (charOfs[i] == temp[j]) {
                    toValue[i] = value[j];
                }
            }
        }

        // 特判
        if (len == 1) {
            return toValue[0];
        }

        // 计算
        int pre = 0;
        while (pre < len) {
            if (pre == len - 1) {
                ans += toValue[pre];
                pre ++;
            } else if (toValue[pre] < toValue[pre + 1]) {
                ans += toValue[pre + 1] - toValue[pre];
                pre += 2;
            } else {
                ans += toValue[pre];
                pre ++;
            }
        }

        return ans;
    }
}