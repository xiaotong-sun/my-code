package exercise4;


import java.util.Arrays;

class Solution {
    public int removeDuplicates(int[] nums) {
        int Null = 10001;
        int L = nums.length;
        int L2 = nums.length;
        int count = 0;
        int temp1 = 0;
        for (int i = 0; i < L; i ++) {
            if (nums[i] == nums[temp1]) {
                count ++;
                if (count >= 3) {
                    nums[i] = Null;
                    L2 --;
                }
            } else {
                temp1 = i;
                count = 1;
            }
        }
        Arrays.sort(nums);
        for (int i = 0; i < L2; i ++) {
            System.out.println(nums[i]);
        }
        return L2;
    }

    public static void main(String[] args) {
        Solution a = new Solution();
        int[] nums = {1,1,1,2,2,2,2,3,3,3,3,4};
        int L = a.removeDuplicates(nums);
        System.out.println(L);
    }
}