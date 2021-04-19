/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
链接：https://leetcode-cn.com/problems/remove-element
*/

class Solution {
    public int removeElement(int[] nums, int val) {
        if (nums.length == 0) {
            return 0;
        }
		// 利用头指针和尾指针的方法解决问题
        int head = 0;
        int tail = nums.length - 1;
        while(head < tail) {
            if (nums[head] == val && nums[tail] != val) {
                int temp = nums[tail];
                nums[tail] = nums[head];
                nums[head] = temp;
                head ++;
                tail --;
            } else if (nums[head] != val){
                head ++;
            } else if (nums[tail] == val) {
                tail --;
            }
        }
		// 需要对循环结束后的结果进行特判，结束时为head == tail，但nums[tail]有可能等于val
        if (nums[head] == val) {
            return head;
        }
        return head + 1;
    }
}