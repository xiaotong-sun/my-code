class Solution {
    public int removeElement(int[] nums, int val) {
        int left = 0;
        int right = 0;
		// 利用左右双指针解决问题
        while(right < nums.length) {
            if (nums[right] != val) {
                nums[left ++] = nums[right ++];
            } else {
                right ++;
            }
        }
		// 注意return的不是left + 1
        return left;
    }
}