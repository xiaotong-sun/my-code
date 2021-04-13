class Solution {
    public String largestNumber(int[] nums) {
        int[] result;
        result = sort(nums);
        StringBuilder answer = new StringBuilder();
        for (int i: result) {
            answer.append(i);
        }
        if (result[0] == 0){
            return "0";
        } else {
            return answer.toString();
        }
    }

    public int[] sort(int[] nums) {
        if (nums.length == 1) {
            return nums;
        }
        int middle = nums.length / 2;
        int[] left = Arrays.copyOfRange(nums, 0, middle);
        int[] right = Arrays.copyOfRange(nums, middle, nums.length);
        return merge(sort(left), sort(right));
    }

    public int[] merge(int[] left, int[] right) {
        int[] result = new int[left.length + right.length];
        int i = 0, j = 0, k = 0;
        while (i < left.length && j < right.length) {
            String first = left[i] + "" + right[j];
            String second = right[j] + "" + left[i];
            long num1 = Long.parseLong(first);
            long num2 =  Long.parseLong(second);
            if (num1 > num2) {
                result[k ++] = left[i ++];
            } else {
                result[k ++] = right[j ++];
            }
        }
        while (i < left.length) {
            result[k ++] = left[i ++];
        }
        while (j < right.length) {
            result[k ++] = right[j ++];
        }
        return result;
    }
}